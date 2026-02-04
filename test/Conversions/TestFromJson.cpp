#include <gtest/gtest.h>
#include <VelyraUtils/Conversions/Json.hpp>

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
};

TEST_F(TestFromJson, BasicTypes) {
    const nlohmann::json j = 5;
    EXPECT_EQ(fromJson<int>(j), 5);

    const nlohmann::json j2 = 3.14;
    EXPECT_DOUBLE_EQ(fromJson<double>(j2), 3.14);
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