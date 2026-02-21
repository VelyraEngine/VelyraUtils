#include <gtest/gtest.h>
#include <VelyraUtils/Logging.hpp>

#include "Utils.hpp"

using namespace Velyra;

class TestVlEnum: public ::testing::Test {};

TEST_F(TestVlEnum, MyColorsToString) {
    EXPECT_EQ(_toString(COLOR_UNKNOWN), "COLOR_UNKNOWN");
    EXPECT_EQ(_toString(COLOR_RED), "COLOR_RED");
    EXPECT_EQ(_toString(COLOR_GREEN), "COLOR_GREEN");
    EXPECT_EQ(_toString(COLOR_BLUE), "COLOR_BLUE");
    EXPECT_EQ(_toString(COLOR_YELLOW), "COLOR_YELLOW");
    EXPECT_EQ(_toString(COLOR_MAX_VALUE), "COLOR_MAX_VALUE");
}

TEST_F(TestVlEnum, MyColorsFromString) {
    EXPECT_EQ(_fromString<COLOR>("COLOR_UNKNOWN"), COLOR_UNKNOWN);
    EXPECT_EQ(_fromString<COLOR>("COLOR_RED"), COLOR_RED);
    EXPECT_EQ(_fromString<COLOR>("COLOR_GREEN"), COLOR_GREEN);
    EXPECT_EQ(_fromString<COLOR>("COLOR_BLUE"), COLOR_BLUE);
    EXPECT_EQ(_fromString<COLOR>("COLOR_YELLOW"), COLOR_YELLOW);
    EXPECT_EQ(_fromString<COLOR>("COLOR_NOT_EXIST"), COLOR_MAX_VALUE);
}

TEST_F(TestVlEnum, MyColorsLog) {
    const Utils::LogPtr logger = Utils::getLogger("TEST-COLOR");

    COLOR myColor = COLOR_GREEN;
    SPDLOG_LOGGER_INFO(logger, "My Color is {} cool", myColor);
    SPDLOG_LOGGER_INFO(logger, "Another Color is {}", COLOR_BLUE);
}

TEST_F(TestVlEnum, MyShapesToString) {
    EXPECT_EQ(_toString(SHAPE_UNKNOWN), "SHAPE_UNKNOWN");
    EXPECT_EQ(_toString(SHAPE_CIRCLE), "SHAPE_CIRCLE");
    EXPECT_EQ(_toString(SHAPE_SQUARE), "SHAPE_SQUARE");
    EXPECT_EQ(_toString(SHAPE_TRIANGLE), "SHAPE_TRIANGLE");
    EXPECT_EQ(_toString(SHAPE_MAX_VALUE), "SHAPE_MAX_VALUE");
}

TEST_F(TestVlEnum, MyShapesFromString) {
    EXPECT_EQ(_fromString<SHAPE>("SHAPE_UNKNOWN"), SHAPE_UNKNOWN);
    EXPECT_EQ(_fromString<SHAPE>("SHAPE_CIRCLE"), SHAPE_CIRCLE);
    EXPECT_EQ(_fromString<SHAPE>("SHAPE_SQUARE"), SHAPE_SQUARE);
    EXPECT_EQ(_fromString<SHAPE>("SHAPE_TRIANGLE"), SHAPE_TRIANGLE);
    EXPECT_EQ(_fromString<SHAPE>("SHAPE_NOT_EXIST"), SHAPE_MAX_VALUE);
}

TEST_F(TestVlEnum, MyShapesLog) {
    const Utils::LogPtr logger = Utils::getLogger("TEST-SHAPE");

    SHAPE myShape = SHAPE_CIRCLE;
    SPDLOG_LOGGER_INFO(logger, "My shape is {} cool", myShape);
    SPDLOG_LOGGER_INFO(logger, "Another Shape is {}", SHAPE_SQUARE);
}
