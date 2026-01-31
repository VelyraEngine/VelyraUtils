#include <VelyraUtils/Threading/Worker.hpp>

namespace Velyra::Utils {

Worker::Worker() {
    _thread = std::thread(&Worker::run, this);
}

Worker::~Worker() {
    stop();
    if (_thread.joinable()) {
        _thread.join();
    }
}

void Worker::submit(std::function<void()> job) {
    if (!job) {
        return;
    }
    {
        std::lock_guard<std::mutex> lock(_mutex);
        _queue.push(std::move(job));
    }
    _cv.notify_one();
}

void Worker::stop() {
    _stopRequested = true;
    _cv.notify_one();
}

void Worker::stopAndClear() {
    _stopRequested = true;
    {
        std::lock_guard<std::mutex> lock(_mutex);
        while (!_queue.empty()) {
            _queue.pop();
        }
    }
    _cv.notify_one();
}

void Worker::wait() {
    std::unique_lock<std::mutex> lock(_mutex);
    _waitCv.wait(lock, [this] {
        return (_queue.empty() && _jobsInFlight == 0) || !_running;
    });
}

void Worker::run() {
    while (_running) {
        std::function<void()> job;
        {
            std::unique_lock<std::mutex> lock(_mutex);
            _cv.wait(lock, [this] {
                return _stopRequested || !_queue.empty();
            });
            if (_stopRequested && _queue.empty()) {
                _running = false;
                _cv.notify_all();
                _waitCv.notify_all();
                return;
            }
            if (!_queue.empty()) {
                job = std::move(_queue.front());
                _queue.pop();
                ++_jobsInFlight;
            }
        }
        if (job) {
            try {
                job();
            } catch (...) {
                // Swallow exceptions to keep worker alive; caller can capture in job
            }
            --_jobsInFlight;
            _waitCv.notify_all();
        }
    }
    _cv.notify_all();
    _waitCv.notify_all();
}

bool Worker::isRunning() const {
    return _running.load();
}

Size Worker::pendingCount() const {
    std::lock_guard<std::mutex> lock(_mutex);
    return _queue.size();
}

} // namespace Velyra::Utils
