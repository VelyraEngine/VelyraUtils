#include <VelyraUtils/Threading/Worker.hpp>

namespace Velyra::Utils {

    Worker::Worker() {
        m_Thread = std::thread(&Worker::run, this);
    }

    Worker::~Worker() {
        stop();
        if (m_Thread.joinable()) {
            m_Thread.join();
        }
    }

    void Worker::submit(std::function<void()> job) {
        if (!job) {
            return;
        }
        {
            std::lock_guard<std::mutex> lock(m_Mutex);
            m_Queue.push(std::move(job));
        }
        m_Cv.notify_one();
    }

    void Worker::stop() {
        m_StopRequested = true;
        m_Cv.notify_one();
    }

    void Worker::stopAndClear() {
        m_StopRequested = true;
        {
            std::lock_guard<std::mutex> lock(m_Mutex);
            while (!m_Queue.empty()) {
                m_Queue.pop();
            }
        }
        m_Cv.notify_one();
    }

    void Worker::wait() {
        std::unique_lock<std::mutex> lock(m_Mutex);
        m_WaitCv.wait(lock, [this] {
            return (m_Queue.empty() && m_JobsInFlight == 0) || !m_Running;
        });
    }

    void Worker::run() {
        while (m_Running) {
            std::function<void()> job;
            {
                std::unique_lock<std::mutex> lock(m_Mutex);
                m_Cv.wait(lock, [this] {
                    return m_StopRequested || !m_Queue.empty();
                });
                if (m_StopRequested && m_Queue.empty()) {
                    m_Running = false;
                    m_Cv.notify_all();
                    m_WaitCv.notify_all();
                    return;
                }
                if (!m_Queue.empty()) {
                    job = std::move(m_Queue.front());
                    m_Queue.pop();
                    ++m_JobsInFlight;
                }
            }
            if (job) {
                try {
                    job();
                } catch (...) {
                    // Swallow exceptions to keep worker alive; caller can capture in job
                }
                --m_JobsInFlight;
                m_WaitCv.notify_all();
            }
        }
        m_Cv.notify_all();
        m_WaitCv.notify_all();
    }

    bool Worker::isRunning() const {
        return m_Running.load();
    }

    Size Worker::pendingCount() const {
        std::lock_guard<std::mutex> lock(m_Mutex);
        return m_Queue.size();
    }

} // namespace Velyra::Utils
