#pragma once

#include <VelyraUtils/ExportUtils.hpp>
#include <VelyraUtils/Types/Types.hpp>

#include <atomic>
#include <condition_variable>
#include <functional>
#include <mutex>
#include <queue>
#include <thread>
#include <vector>

namespace Velyra::Utils {

/**
 * Thread pool that executes jobs in parallel using a fixed number of threads.
 * Jobs are submitted via submit() and run in any order by available threads.
 */
class VL_API ThreadPool {
public:
    /** Create a pool with the given number of worker threads. */
    explicit ThreadPool(Size numThreads);
    ~ThreadPool();

    ThreadPool(const ThreadPool&) = delete;
    ThreadPool& operator=(const ThreadPool&) = delete;
    ThreadPool(ThreadPool&&) noexcept = delete;
    ThreadPool& operator=(ThreadPool&&) noexcept = delete;

    /** Submit a job to be executed by any thread. Thread-safe. */
    void submit(std::function<void()> job);

    /** Stop the pool after current jobs finish. Pending jobs remain in queue. */
    void stop();

    /** Stop and discard any pending jobs. */
    void stopAndClear();

    /** Block until all submitted jobs have completed. */
    void wait();

    /** Whether the pool is running (threads are active). */
    [[nodiscard]] bool isRunning() const;

    /** Number of jobs currently queued (not yet started). */
    [[nodiscard]] Size pendingCount() const;

    /** Number of worker threads. */
    [[nodiscard]] Size threadCount() const;

private:
    void workerLoop();

    std::queue<std::function<void()>> _queue;
    mutable std::mutex _mutex;
    std::condition_variable _cv;
    std::condition_variable _waitCv;
    std::vector<std::thread> _threads;
    std::atomic<bool> _running{true};
    std::atomic<bool> _stopRequested{false};
    std::atomic<Size> _jobsInFlight{0};
};

} // namespace Velyra::Utils
