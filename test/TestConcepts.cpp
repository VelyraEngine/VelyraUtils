#include <gtest/gtest.h>

#include <nlohmann/json.hpp>
#include <VelyraUtils/Concepts.hpp>

using namespace Velyra;
using namespace Velyra::Utils;

class TestConcepts : public ::testing::Test {};

struct TypeTraitsData {
    double x = 0.0;
    double y = 0.0;

    [[nodiscard]] nlohmann::json toJson() const {
        nlohmann::json j;
        j["x"] = x;
        j["y"] = y;
        return j;
    }

    void fromJson(const nlohmann::json& j) {
        x = j.at("x").get<double>();
        y = j.at("y").get<double>();
    }
};

TEST_F(TestConcepts, HasToFromJson) {
    EXPECT_FALSE(HasToJson<int>);
    EXPECT_FALSE(HasToJson<double>);
    EXPECT_TRUE(HasToJson<TypeTraitsData>);

    EXPECT_FALSE(HasFromJson<int>);
    EXPECT_FALSE(HasFromJson<double>);
    EXPECT_TRUE(HasFromJson<TypeTraitsData>);

    EXPECT_FALSE(JsonSerializable<int>);
    EXPECT_FALSE(JsonSerializable<double>);
    EXPECT_TRUE(JsonSerializable<TypeTraitsData>);
}