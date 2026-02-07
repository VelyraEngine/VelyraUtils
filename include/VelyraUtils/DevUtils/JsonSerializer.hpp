#pragma once

#include <VelyraUtils/Conversions/Json.hpp>
#include <VelyraUtils/DevUtils/MacroExpansion.hpp>

namespace Velyra::Utils::Detail {

    template<typename T>
    void jsonAssign(nlohmann::json& j, const std::string& key, const T& value) {
        j[key] = toJson<T>(value);
    }

    template<typename T>
    void jsonRead(const nlohmann::json& j, const std::string& key, T& value) {
        value = fromJson<T>(j.at(key));
    }
}

#define VL_JSON_OBJECT_NAME _nlohmann_json
#define VL_TO_JSON(v1) Velyra::Utils::Detail::jsonAssign<decltype(v1)>(VL_JSON_OBJECT_NAME, #v1, v1);
#define VL_FROM_JSON(v1) Velyra::Utils::Detail::jsonRead<decltype(v1)>(VL_JSON_OBJECT_NAME, #v1, v1);

#define VL_GENERATE_JSON_SERIALIZER(Type, ...)                     \
    nlohmann::json toJson() const {                                 \
        nlohmann::json VL_JSON_OBJECT_NAME;                     \
        VL_EXPAND(VL_APPLY(VL_TO_JSON, __VA_ARGS__))    \
        return VL_JSON_OBJECT_NAME;                             \
    }                                                               \
                                                                    \
    void fromJson(const nlohmann::json &VL_JSON_OBJECT_NAME) {  \
        VL_EXPAND(VL_APPLY(VL_FROM_JSON, __VA_ARGS__))  \
    }
