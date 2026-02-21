#include <gtest/gtest.h>
#include <VelyraUtils/Conversions/String.hpp>

#include "../Utils.hpp"

using namespace Velyra;
using namespace Velyra::Utils;

class TestToString : public ::testing::Test {};

TEST_F(TestToString, BasicTypes) {
    EXPECT_EQ(toString(42), "42");
    EXPECT_EQ(toString(3.14), "3.140000");
    EXPECT_EQ(toString(true), "1");
    EXPECT_EQ(toString(false), "0");
}

TEST_F(TestToString, VlEnum) {
    EXPECT_EQ(toString(COLOR_RED), "COLOR_RED");
    EXPECT_EQ(toString(SHAPE_TRIANGLE), "SHAPE_TRIANGLE");
}

TEST_F(TestToString, TimePoint) {
    const TimePoint tp = timeFromEpoch(1700000000000.0); // 2024-11-14T22:13:20Z
    EXPECT_EQ(toString(tp), "2023-11-14T22:13:20");
}
