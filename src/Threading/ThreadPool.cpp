#include <VelyraUtils/Threading/ThreadPool.hpp>

namespace Velyra::Utils {

ThreadPool::ThreadPool(Size numThreads) {
    if (numThreads == 0) {
        numThreads = 1;
    }
    _threads.reserve(numThreads);
    for (Size i = 0; i < numThreads; ++i) {
        _threads.emplace_back(&ThreadPool::workerLoop, this);
    }
}

ThreadPool::~ThreadPool() {
    stop();
    for (auto& t : _threads) {
        if (t.joinable()) {
            t.join();
        }
    }
}

void ThreadPool::submit(std::function<void()> job) {
    if (!job) {
        return;
    }
    {
        std::lock_guard<std::mutex> lock(_mutex);
        _queue.push(std::move(job));
    }
    _cv.notify_one();
}

void ThreadPool::stop() {
    _stopRequested = true;
    _cv.notify_all();
}

void ThreadPool::stopAndClear() {
    _stopRequested = true;
    {
        std::lock_guard<std::mutex> lock(_mutex);
        while (!_queue.empty()) {
            _queue.pop();
        }
    }
    _cv.notify_all();
}

void ThreadPool::wait() {
    std::unique_lock<std::mutex> lock(_mutex);
    _waitCv.wait(lock, [this] {
        return (_queue.empty() && _jobsInFlight == 0) || !_running;
    });
}

void ThreadPool::workerLoop() {
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
                _jobsInFlight++;
            }
        }
        if (job) {
            try {
                job();
            } catch (...) {
                // Swallow exceptions; caller can capture in job
            }
            _jobsInFlight--;
            _waitCv.notify_all();
        }
    }
}

bool ThreadPool::isRunning() const {
    return _running.load();
}

Size ThreadPool::pendingCount() const {
    std::lock_guard<std::mutex> lock(_mutex);
    return _queue.size();
}

Size ThreadPool::threadCount() const {
    return _threads.size();
}

} // namespace Velyra::Utils
