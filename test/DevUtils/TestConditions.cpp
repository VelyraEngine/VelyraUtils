#include <gtest/gtest.h>
#include <VelyraUtils/DevUtils/Conditions.hpp>

class TestConditions: public ::testing::Test {
};

TEST_F(TestConditions, Assert) {
    EXPECT_DEATH(VL_ASSERT(true == false, "This is an assert test with value: {}", 42), "");
    EXPECT_DEATH(VL_ASSERT(true == false, "This assert message has no additional values"), "");

    EXPECT_DEATH(VL_PRECONDITION(true == false, "This is an precondition test with value: {}", 42), "");
    EXPECT_DEATH(VL_PRECONDITION(true == false, "This precondition message has no additional values"), "");

    EXPECT_DEATH(VL_POSTCONDITION(true == false, "This is an postcondition test with value: {}", 42), "");
    EXPECT_DEATH(VL_POSTCONDITION(true == false, "This postcondition message has no additional values"), "");
}

TEST_F(TestConditions, NoDeath) {
    VL_ASSERT(true == true, "This assert should not trigger");
    VL_PRECONDITION(true == true, "This precondition should not trigger");
    VL_POSTCONDITION(true == true, "This postcondition should not trigger");
}

TEST_F(TestConditions, FormattedThrow) {
    bool catched = false;
    try {
        VL_THROW("This is a formatted throw with value: {}", 42);
    } catch (const std::runtime_error& e) {
        catched = true;
        EXPECT_STREQ(e.what(), "This is a formatted throw with value: 42");
    }
    EXPECT_TRUE(catched);
}

TEST_F(TestConditions, NotImplementedThrow) {
    bool catched = false;
    try {
        VL_NOT_IMPLEMENTED();
    } catch (const std::runtime_error& e) {
        catched = true;
        std::string expectedStart = "Function not yet implemented: ";
        std::string actualMessage = e.what();
        EXPECT_EQ(actualMessage.substr(0, expectedStart.size()), expectedStart);
    }
    EXPECT_TRUE(catched);
}