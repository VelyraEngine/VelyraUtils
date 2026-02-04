#pragma once

#include <nlohmann/json.hpp>
#include <VelyraUtils/DevUtils/Conditions.hpp>
#include <VelyraUtils/TypeTraits.hpp>
#include <VelyraUtils/Concepts.hpp>

namespace Velyra::Utils {

    template<typename T>
    nlohmann::json toJson(const T& value) {
        if constexpr (nlohmann::detail::is_compatible_type<nlohmann::json, T>::value) {
            return value;
        }
        else if constexpr (ArrayLike<T>) {
            nlohmann::json j = nlohmann::json::array();
            for (const auto& element: value) {
                j.push_back(toJson<decltype(element)>(element));
            }
            return j;
        }
        else if constexpr(HasToJson<T>) {
            return value.toJson();
        }
        else {
            static_assert(always_false_v<T>, "Unsupported type for toJson");
            VL_THROW("Cannot convert type {} to json", typeid(T).name()); // prevent -wreturn
        }
    }

    template<typename T>
    T fromJson(const nlohmann::json& json) {
        if constexpr (nlohmann::detail::is_compatible_type<nlohmann::json, T>::value) {
            if constexpr (nlohmann::detail::is_compatible_reference_type<nlohmann::json, T>::value) {
                return json.get_ref<T>();
            }
            else {
                return json.get<T>();
            }
        }
        else if constexpr(HasFromJson<T>) {
            T value;
            value.fromJson(json);
            return value;;
        }
        else {
            static_assert(always_false_v<T>, "Unsupported type for fromJson");
            VL_THROW("Cannot convert type {} from json", typeid(T).name()); // prevent -wreturn
        }
    }

}