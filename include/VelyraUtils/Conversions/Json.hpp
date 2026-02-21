#pragma once

#include <nlohmann/json.hpp>
#include <VelyraUtils/DevUtils/Conditions.hpp>
#include <VelyraUtils/TypeTraits.hpp>
#include <VelyraUtils/Concepts.hpp>
#include <VelyraUtils/VelyraEnum.hpp>

namespace Velyra::Utils {

    template<typename T>
    nlohmann::json toJson(const T& value) {
        if constexpr (IsVlEnum<T>) {
            return toString(value);
        }
        else if constexpr (nlohmann::detail::is_compatible_type<nlohmann::json, T>::value) {
            return value;
        }
        else if constexpr (ArrayLike<T>) {
            nlohmann::json j = nlohmann::json::array();
            for (const auto& element: value) {
                j.push_back(toJson<decltype(element)>(element));
            }
            return j;
        }
        else if constexpr (MapLike<T>) {
            nlohmann::json j = nlohmann::json::object();
            for (const auto& [key, v]: value) {
                j[toJson<decltype(key)>(key)] = toJson<decltype(v)>(v);
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
        if constexpr (IsVlEnum<T>) {
            return fromString<T>(json.get<std::string>());
        }
        else if constexpr (nlohmann::detail::is_compatible_type<nlohmann::json, T>::value) {
            if constexpr (std::is_reference_v<T>) {
                return json.get_ref<T>();
            }
            else {
                return json.get<T>();
            }
        }
        else if constexpr (ArrayLike<T>) {
            T container;
            for (const auto& element: json) {
                container.push_back(fromJson<typename T::value_type>(element));
            }
            return container;
        }
        else if constexpr (MapLike<T>) {
            T container;
            for (auto it = json.begin(); it != json.end(); ++it) {
                auto key = fromJson<typename T::key_type>(it.key());
                auto value = fromJson<typename T::mapped_type>(it.value());
                container[key] = value;
            }
            return container;
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