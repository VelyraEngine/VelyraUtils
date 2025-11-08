#include <gtest/gtest.h>

#include <VelyraUtils/Logging.hpp>

using namespace Velyra;

class TestLogging: public ::testing::Test {

};

TEST_F(TestLogging, CreateLogger) {
    const std::string loggerName = "TST-HEL";

    Utils::LogPtr logger = Utils::getLogger(loggerName);
    ASSERT_NE(logger, nullptr);

    SPDLOG_LOGGER_TRACE(logger, "Trace message");

}

