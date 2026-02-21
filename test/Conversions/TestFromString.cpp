#include <gtest/gtest.h>
#include <VelyraUtils/Conversions/String.hpp>

#include "../Utils.hpp"

using namespace Velyra;
using namespace Velyra::Utils;

class TestFromString : public ::testing::Test {};

TEST_F(TestFromString, BasicTypes) {
    EXPECT_EQ(fromString<int>("42"), 42);
    EXPECT_DOUBLE_EQ(fromString<double>("3.14"), 3.14);
}

TEST_F(TestFromString, VlEnum) {
    EXPECT_EQ(fromString<COLOR>("COLOR_RED"), COLOR_RED);
    EXPECT_EQ(fromString<SHAPE>("SHAPE_TRIANGLE"), SHAPE_TRIANGLE);
}

TEST_F(TestFromString, TimePoint) {
    const std::string time_str = "2024-01-01T12:00:00";
    const TimePoint tp = fromString<TimePoint>(time_str);
    const std::string converted_back = toString(tp);
    EXPECT_EQ(time_str, converted_back);
}