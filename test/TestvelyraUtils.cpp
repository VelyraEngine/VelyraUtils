#include <gtest/gtest.h>
#include <VelyraUtils/DevUtils/PrivateMemberGetter.hpp>
#include <VelyraUtils/Concepts.hpp>

using namespace Velyra;

class TestVelyraUtils: public ::testing::Test {

};

class GetPrivateMember {
public:
    GetPrivateMember():
    m_PrivateInt(5){}

private:
    int m_PrivateInt = 0;

    VL_GET_PRIVATE_MEMBER(GetPrivateMember, m_PrivateInt)
};

TEST_F(TestVelyraUtils, VL_TESTING_macro) {
    int macro_enabled = -1;
#if defined(VL_TESTING)
    macro_enabled = 1;
#else
    macro_enabled = 0;
#endif
    EXPECT_EQ(macro_enabled, 1);
}

TEST_F(TestVelyraUtils, PrivateMember) {
    const GetPrivateMember example;
    EXPECT_EQ(example.get_m_PrivateInt(), 5);
}