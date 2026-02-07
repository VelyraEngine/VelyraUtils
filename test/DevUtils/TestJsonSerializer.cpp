#include <gtest/gtest.h>
#include <VelyraUtils/DevUtils/JsonSerializer.hpp>

#include "../Utils.hpp"

using namespace Velyra;
using namespace Velyra::Utils;

class TestJsonSerializer : public ::testing::Test {};

struct TestData {
    int a = 1;
    double b = 3.14;
    bool c = true;

    VL_GENERATE_JSON_SERIALIZER(TestData, a, b, c)
};

struct TestData2 {
    COLOR fruit = COLOR_MAX_VALUE;

    VL_GENERATE_JSON_SERIALIZER(TestData2, fruit)
};

TEST_F(TestJsonSerializer, BasicTypes) {
    const TestData original;
    const nlohmann::json j = original.toJson();

    TestData deserialized;
    deserialized.fromJson(j);

    EXPECT_EQ(original.a, deserialized.a);
    EXPECT_DOUBLE_EQ(original.b, deserialized.b);
    EXPECT_EQ(original.c, deserialized.c);
}

