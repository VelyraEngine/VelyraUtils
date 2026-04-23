#pragma once

#include <VelyraUtils/VelyraEnum.hpp>
#include <nlohmann/json.hpp>

VL_ENUM(COLOR, int,
    COLOR_UNKNOWN = 0,
    COLOR_RED = 1,
    COLOR_GREEN = 2,
    COLOR_BLUE = 4,
    COLOR_YELLOW = 8
);

VL_ENUM(SHAPE, int,
    SHAPE_UNKNOWN,
    SHAPE_CIRCLE,
    SHAPE_SQUARE,
    SHAPE_TRIANGLE
);

struct ConversionData {
    int b = 0;
    std::string c = "poeder";

    nlohmann::json toJson() const {
        nlohmann::json j;
        j["b"] = b;
        j["c"] = c;
        return j;
    }

    void fromJson(const nlohmann::json& j) {
        b = j.at("b").get<int>();
        c = j.at("c").get<std::string>();
    }

    bool operator==(const ConversionData& other) const {
        return b == other.b && c == other.c;
    }
};