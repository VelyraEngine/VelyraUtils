#include <gtest/gtest.h>

#include <VelyraUtils/Logging.hpp>
#include <VelyraUtils/CpuFeatures.hpp>

using namespace Velyra;

class TestLogging: public ::testing::Test {

};

TEST_F(TestLogging, CreateLogger) {
    const std::string loggerName = "TST-HEL";

    Utils::LogPtr logger = Utils::getLogger(loggerName);
    ASSERT_NE(logger, nullptr);

    SPDLOG_LOGGER_TRACE(logger, "Trace message");
}

TEST_F(TestLogging, DetectCpuFeatures) {
    auto [sse2, avx, avx2] = Utils::detectCpuFeatures();
    SPDLOG_INFO("CPU Features - SSE2: {}, AVX: {}, AVX2: {}", sse2, avx, avx2);
}

