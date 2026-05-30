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

        void submit(std::function<void()> job);

        /** Stop the worker after the current job (if any) finishes. Pending jobs remain in queue. */
        void stop();

        /**
         * @brief Stop and discard any pending jobs.
         */
        void stopAndClear();

        /**
         * @brief Block until the current job (if any) and all queued jobs are
         * done.
         */
        void wait();

        /**
         * @brief Whether the worker thread is running.
         * @return
         */
        [[nodiscard]] bool isRunning() const;

        /**
         * @brief Number of jobs currently queued (not yet started).
         * @return Size
         */
        [[nodiscard]] Size pendingCount() const;

    private:
        void run();

        std::queue<std::function<void()>> m_Queue;
        mutable std::mutex m_Mutex;
        std::condition_variable m_Cv;
        std::condition_variable m_WaitCv;
        std::thread m_Thread;
        std::atomic<bool> m_Running = true;
        std::atomic<bool> m_StopRequested = false;
        std::atomic<Size> m_JobsInFlight{0};
    };

} // namespace Velyra::Utils
