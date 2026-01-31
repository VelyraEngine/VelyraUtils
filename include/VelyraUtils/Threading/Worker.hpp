#pragma once

#include <VelyraUtils/ExportUtils.hpp>
#include <VelyraUtils/Types/Types.hpp>

#include <atomic>
#include <condition_variable>
#include <functional>
#include <mutex>
#include <queue>
#include <thread>

namespace Velyra::Utils {

/**
 * Single-threaded worker that executes jobs in FIFO order.
 * Jobs are submitted via submit() and run sequentially on a dedicated thread.
 */
class VL_API Worker {
public:
    Worker();
    ~Worker();

    Worker(const Worker&) = delete;
    Worker& operator=(const Worker&) = delete;
    Worker(Worker&&) noexcept = delete;
    Worker& operator=(Worker&&) noexcept = delete;

    /** Submit a job to be executed in order. Thread-safe. */
    void submit(std::function<void()> job);

    /** Stop the worker after the current job (if any) finishes. Pending jobs remain in queue. */
    void stop();

    /** Stop and discard any pending jobs. */
    void stopAndClear();

    /** Block until the current job (if any) and all queued jobs are done. */
    void wait();

    /** Whether the worker thread is running. */
    [[nodiscard]] bool isRunning() const;

    /** Number of jobs currently queued (not yet started). */
    [[nodiscard]] Size pendingCount() const;

private:
    void run();

    std::queue<std::function<void()>> _queue;
    mutable std::mutex _mutex;
    std::condition_variable _cv;
    std::condition_variable _waitCv;
    std::thread _thread;
    std::atomic<bool> _running{true};
    std::atomic<bool> _stopRequested{false};
    std::atomic<Size> _jobsInFlight{0};
};

} // namespace Velyra::Utils
