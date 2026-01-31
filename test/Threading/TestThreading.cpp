#include <gtest/gtest.h>

#include <VelyraUtils/Threading/Worker.hpp>
#include <VelyraUtils/Threading/ThreadPool.hpp>

#include <atomic>
#include <chrono>
#include <thread>

using namespace Velyra::Utils;

class TestWorker : public ::testing::Test {
};

TEST_F(TestWorker, ExecutesSingleJob) {
    std::atomic<bool> done{false};
    Worker w;
    w.submit([&done] { done = true; });
    while (!done) {
        std::this_thread::yield();
    }
    w.stop();
    w.wait();
    EXPECT_TRUE(done);
}

TEST_F(TestWorker, ExecutesJobsInOrder) {
    std::vector<int> order;
    std::mutex m;
    Worker w;
    for (int i = 0; i < 5; ++i) {
        int copy = i;
        w.submit([&order, &m, copy] {
            std::lock_guard<std::mutex> lock(m);
            order.push_back(copy);
        });
    }
    w.wait();
    w.stop();
    w.wait();
    EXPECT_EQ(order.size(), 5u);
    for (size_t i = 0; i < order.size(); ++i) {
        EXPECT_EQ(order[i], static_cast<int>(i)) << "Order violated at index " << i;
    }
}

TEST_F(TestWorker, PendingCount) {
    std::atomic<bool> block{true};
    Worker w;
    w.submit([&block] {
        while (block) {
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }
    });
    while (w.pendingCount() != 0) {
        std::this_thread::yield();
    }
    w.submit([] {});
    w.submit([] {});
    EXPECT_GE(w.pendingCount(), 1u);
    block = false;
    w.wait();
    w.stop();
    w.wait();
}

TEST_F(TestWorker, StopAndClear) {
    std::atomic<int> executed{0};
    Worker w;
    for (int i = 0; i < 10; ++i) {
        w.submit([&executed] { executed++; });
    }
    w.stopAndClear();
    w.wait();
    int count = executed.load();
    EXPECT_LT(count, 10) << "stopAndClear should have discarded some jobs";
}

TEST_F(TestWorker, ExceptionInJobDoesNotKillWorker) {
    std::atomic<int> afterThrow{0};
    Worker w;
    w.submit([] { throw std::runtime_error("test"); });
    w.submit([&afterThrow] { afterThrow = 1; });
    w.wait();
    w.stop();
    w.wait();
    EXPECT_EQ(afterThrow.load(), 1);
}

class TestThreadPool : public ::testing::Test {
};

TEST_F(TestThreadPool, ExecutesJobs) {
    std::atomic<int> count{0};
    const int numJobs = 20;
    ThreadPool pool(4);
    for (int i = 0; i < numJobs; ++i) {
        pool.submit([&count] { count++; });
    }
    pool.wait();
    pool.stop();
    pool.wait();
    EXPECT_EQ(count.load(), numJobs);
}

TEST_F(TestThreadPool, ParallelExecution) {
    std::atomic<int> concurrent{0};
    std::atomic<int> maxConcurrent{0};
    const int numThreads = 4;
    ThreadPool pool(numThreads);
    for (int i = 0; i < numThreads * 2; ++i) {
        pool.submit([&concurrent, &maxConcurrent] {
            int c = ++concurrent;
            {
                int currentMax = maxConcurrent.load();
                while (c > currentMax && !maxConcurrent.compare_exchange_weak(currentMax, c)) {
                }
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(5));
            --concurrent;
        });
    }
    pool.wait();
    pool.stop();
    pool.wait();
    EXPECT_GE(maxConcurrent.load(), 2) << "Jobs should have run in parallel";
}

TEST_F(TestThreadPool, ThreadCount) {
    ThreadPool pool(8);
    EXPECT_EQ(pool.threadCount(), 8u);
    pool.stop();
    pool.wait();
}

TEST_F(TestThreadPool, PendingCount) {
    std::atomic<bool> block{true};
    ThreadPool pool(2);
    for (int i = 0; i < 5; ++i) {
        pool.submit([&block] {
            while (block) {
                std::this_thread::sleep_for(std::chrono::milliseconds(1));
            }
        });
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(20));
    pool.submit([] {});
    pool.submit([] {});
    Size pending = pool.pendingCount();
    EXPECT_GE(pending, 1u);
    block = false;
    pool.wait();
    pool.stop();
    pool.wait();
}

TEST_F(TestThreadPool, StopAndClear) {
    std::atomic<int> executed{0};
    ThreadPool pool(2);
    for (int i = 0; i < 20; ++i) {
        pool.submit([&executed] { executed++; });
    }
    pool.stopAndClear();
    pool.wait();
    int count = executed.load();
    EXPECT_LT(count, 20) << "stopAndClear should have discarded some jobs";
}

TEST_F(TestThreadPool, ExceptionInJobDoesNotKillPool) {
    std::atomic<int> afterThrow{0};
    ThreadPool pool(2);
    pool.submit([] { throw std::runtime_error("test"); });
    pool.submit([&afterThrow] { afterThrow = 1; });
    pool.wait();
    pool.stop();
    pool.wait();
    EXPECT_EQ(afterThrow.load(), 1);
}

TEST_F(TestThreadPool, SingleThreadPool) {
    std::atomic<int> count{0};
    ThreadPool pool(1);
    for (int i = 0; i < 5; ++i) {
        pool.submit([&count] { count++; });
    }
    pool.wait();
    pool.stop();
    pool.wait();
    EXPECT_EQ(count.load(), 5);
}
