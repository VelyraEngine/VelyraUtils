#include <gtest/gtest.h>

#include <VelyraUtils/Math.hpp>

using namespace Velyra;

class TestMath: public ::testing::Test {
};

TEST_F(TestMath, AlmostEqual) {
    EXPECT_TRUE(Utils::almostEqual<float>(0.1f + 0.2f, 0.3f));
    EXPECT_FALSE(Utils::almostEqual<float>(0.1f + 0.2f, 0.3001f));

    EXPECT_TRUE(Utils::almostEqual<double>(0.1 + 0.2, 0.3));
    EXPECT_FALSE(Utils::almostEqual<double>(0.1 + 0.2, 0.3001));
}
