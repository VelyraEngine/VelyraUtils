#include <gtest/gtest.h>
#include <deque>
#include <VelyraUtils/Conversions/Json.hpp>

#include "../Utils.hpp"

using namespace Velyra;
using namespace Velyra::Utils;

class TestFromJson : public ::testing::Test {};

struct ConversionData {
    int b = 0;
    std::string c = "poeder";

    void fromJson(const nlohmann::json& j) {
        b = j.at("b").get<int>();
        c = j.at("c").get<std::string>();
    }

    bool operator==(const ConversionData& other) const {
        return b == other.b && c == other.c;
    }
};

TEST_F(TestFromJson, BasicTypes) {
    const nlohmann::json j = 5;
    EXPECT_EQ(fromJson<int>(j), 5);

    const nlohmann::json j2 = 3.14;
    EXPECT_DOUBLE_EQ(fromJson<double>(j2), 3.14);
}

TEST_F(TestFromJson, VlEnum) {
    const nlohmann::json j = "SHAPE_SQUARE";
    EXPECT_EQ(fromJson<SHAPE>(j), SHAPE_SQUARE);
}

TEST_F(TestFromJson, MemberFromJson) {
    nlohmann::json j;
    j["b"] = 2;
    j["c"] = "Vibe";
    ConversionData d;
    d.fromJson(j);
    EXPECT_EQ(d.b, 2);
    EXPECT_EQ(d.c, "Vibe");
}

TEST_F(TestFromJson, ReferenceType) {
    nlohmann::json j;
    j["string"] = "SomeString";
    EXPECT_EQ(fromJson<const std::string&>(j.at("string")), "SomeString");
}

TEST_F(TestFromJson, Arrays) {
    const nlohmann::json j = {1.0, 2.0, 3.0};
    const std::vector<double> expected = {1.0, 2.0, 3.0};
    EXPECT_EQ(fromJson<std::vector<double>>(j), expected);

    const nlohmann::json dcj = nlohmann::json::parse(R"(
  [
    {
      "b": 0,
      "c": "poeder"
    },
    {
      "b": 0,
      "c": "poeder"
    }
  ]
)");
    const std::deque<ConversionData> expectedDeque = {
        ConversionData(),
        ConversionData()
    };
    EXPECT_EQ(fromJson<std::deque<ConversionData>>(dcj), expectedDeque);
}

TEST_F(TestFromJson, Maps) {
    const nlohmann::json j = {
        {"one", 1},
        {"two", 2}
    };
    const std::map<std::string, int> expected = {
        {"one", 1},
        {"two", 2}
    };
    const auto result = fromJson<std::map<std::string, int>>(j);
    EXPECT_EQ(result, expected);
}