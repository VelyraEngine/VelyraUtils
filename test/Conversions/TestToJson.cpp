#include <deque>
#include <gtest/gtest.h>
#include <VelyraUtils/Conversions/Json.hpp>

using namespace Velyra;
using namespace Velyra::Utils;

class TestToJson : public ::testing::Test {};

struct NoConversionData {
    int a = 0;
};

struct ConversionData {
    int b = 0;
    std::string c = "poeder";

    nlohmann::json toJson() const {
        nlohmann::json j;
        j["b"] = b;
        j["c"] = c;
        return j;
    }
};

TEST_F(TestToJson, BasicTypes) {
    EXPECT_EQ(toJson<int>(5).get<int>(), 5);
    EXPECT_EQ(toJson<double>(3.14).get<double>(), 3.14);
}

TEST_F(TestToJson, MemberToJson) {
    ConversionData data;
    nlohmann::json j = data.toJson();

    EXPECT_EQ(j, toJson<ConversionData>(data));
}

TEST_F(TestToJson, Arrays) {
    const std::vector<double> vd = {1.0, 2.0, 3.0};
    const nlohmann::json vdj = {1.0, 2.0, 3.0};
    EXPECT_EQ(toJson<std::vector<double>>(vd), vdj);

    const std::deque<ConversionData> dc = {
        ConversionData(),
        ConversionData()
    };
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
    EXPECT_EQ(toJson<std::deque<ConversionData>>(dc), dcj);
}