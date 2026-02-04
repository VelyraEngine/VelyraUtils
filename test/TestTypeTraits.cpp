#include <gtest/gtest.h>
#include <VelyraUtils/TypeTraits.hpp>

using namespace Velyra;
using namespace Velyra::Utils;

class TestTypeTraits : public ::testing::Test {};

TEST_F(TestTypeTraits, AlwaysFalse) {
    EXPECT_FALSE(always_false_v<int>);
    EXPECT_FALSE(always_false_v<double>);
}