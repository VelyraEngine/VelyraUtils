#include <gtest/gtest.h>
#include <VelyraUtils/DevUtils/JsonSerializer.hpp>
#include <VelyraUtils/Clock/Clock.hpp>

#include "../Utils.hpp"

using namespace Velyra;
using namespace Velyra::Utils;

class TestJsonSerializer : public ::testing::Test {};

struct BasicTypeSerializer {
    int a = 1;
    double b = 3.14;
    bool c = true;

    VL_GENERATE_JSON_SERIALIZER(TestData, a, b, c)
};

TEST_F(TestJsonSerializer, BasicTypes) {
    const BasicTypeSerializer original;
    const nlohmann::json j = original.toJson();

    BasicTypeSerializer deserialized;
    deserialized.fromJson(j);

    EXPECT_EQ(original.a, deserialized.a);
    EXPECT_DOUBLE_EQ(original.b, deserialized.b);
    EXPECT_EQ(original.c, deserialized.c);
}

struct EnumSerializer {
    COLOR fruit = COLOR_MAX_VALUE;

    VL_GENERATE_JSON_SERIALIZER(TestData2, fruit)
};


TEST_F(TestJsonSerializer, EnumType) {
    const EnumSerializer original;
    const nlohmann::json j = original.toJson();

    EnumSerializer deserialized;
    deserialized.fromJson(j);

    EXPECT_EQ(original.fruit, deserialized.fruit);
}

struct TimeSerializer {
    TimePoint timestamp = timeFromEpoch(1700000000000.0); // 2024-11-14T22:13:20Z
    Duration duration = 2.0s;

    VL_GENERATE_JSON_SERIALIZER(TimeSerializer, timestamp, duration)
};

TEST_F(TestJsonSerializer, TimeTypes) {
    const TimeSerializer original;
    const nlohmann::json j = original.toJson();

    TimeSerializer deserialized;
    deserialized.fromJson(j);

    EXPECT_EQ(original.timestamp, deserialized.timestamp);
    EXPECT_EQ(original.duration.count(), deserialized.duration.count());
}

struct RelaxedSerializer {
    int a = 42;
    double b = 2.718;
    std::string c = "default";

    VL_GENERATE_JSON_SERIALIZER_RELAXED(RelaxedSerializer, a, b, c)
};

TEST_F(TestJsonSerializer, RelaxedDeserializationWithMissingFields) {
    // Create JSON with only some fields
    nlohmann::json j;
    j["a"] = 100;
    // b and c are missing

    RelaxedSerializer deserialized;
    deserialized.fromJson(j);

    // Field 'a' should be updated from JSON
    EXPECT_EQ(100, deserialized.a);
    // Fields 'b' and 'c' should keep their default values
    EXPECT_DOUBLE_EQ(2.718, deserialized.b);
    EXPECT_EQ("default", deserialized.c);
}

TEST_F(TestJsonSerializer, RelaxedDeserializationWithAllFields) {
    // Create JSON with all fields
    nlohmann::json j;
    j["a"] = 100;
    j["b"] = 1.414;
    j["c"] = "updated";

    RelaxedSerializer deserialized;
    deserialized.fromJson(j);

    // All fields should be updated from JSON
    EXPECT_EQ(100, deserialized.a);
    EXPECT_DOUBLE_EQ(1.414, deserialized.b);
    EXPECT_EQ("updated", deserialized.c);
}

TEST_F(TestJsonSerializer, RelaxedDeserializationWithEmptyJson) {
    nlohmann::json j; // Empty JSON

    RelaxedSerializer deserialized;
    deserialized.fromJson(j);

    // All fields should keep their default values
    EXPECT_EQ(42, deserialized.a);
    EXPECT_DOUBLE_EQ(2.718, deserialized.b);
    EXPECT_EQ("default", deserialized.c);
}

