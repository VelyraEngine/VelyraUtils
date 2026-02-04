#pragma once

#include <concepts>
#include <nlohmann/json_fwd.hpp>

namespace Velyra::Utils {

    template<typename T>
    concept HasToJson =
        // const version
        requires (const T& t) {
            { t.toJson() } -> std::convertible_to<nlohmann::json>;
        } ||
        // non-const version
        requires (T& t) {
            { t.toJson() } -> std::convertible_to<nlohmann::json>;
        };

    template<typename T>
    concept HasFromJson =
        // const version
        requires(T& t, const nlohmann::json& j) {
            { t.fromJson(j) } -> std::same_as<void>;
        } ||
        requires(T& t, nlohmann::json& j) {
            { t.fromJson(j) } -> std::same_as<void>;
        };

    template<typename T>
    concept JsonSerializable = HasToJson<T> && HasFromJson<T>;

    template<typename T>
    concept MapLike = requires {
        T::key_type;
        T::mapped_type;
    };

    template<typename T>
    concept StringLike =
        std::same_as<std::decay_t<T>, std::string> ||
        std::same_as<std::decay_t<T>, std::string_view>;

    template<typename T>
    concept ArrayLike =
        std::ranges::range<T> &&
        !StringLike<T> &&
        !MapLike<T>;

}