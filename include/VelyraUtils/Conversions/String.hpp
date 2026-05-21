#pragma once

#include <VelyraUtils/DevUtils/Conditions.hpp>
#include <VelyraUtils/TypeTraits.hpp>
#include <VelyraUtils/Concepts.hpp>
#include <VelyraUtils/VelyraEnum.hpp>
#include <VelyraUtils/DevUtils/Fmt.hpp>
#include <VelyraUtils/Clock/Clock.hpp>
#include <sstream>

namespace Velyra::Utils {

    template<typename T>
    std::string toString(const T& value) {
        if constexpr (IsVlEnum<T>) {
            return _toString(value);
        }
        else if constexpr (std::is_same_v<T, TimePoint>) {
            using namespace std::chrono;
            auto sys_time = floor<seconds>(time_point_cast<system_clock::duration>(value));

            // convert to time_t
            std::time_t t = system_clock::to_time_t(sys_time);

            // UTC
            std::tm tm = *std::gmtime(&t);

            std::ostringstream oss;
            oss << std::put_time(&tm, STRING_FORMAT.data());
            return oss.str();
        }
        else if constexpr (std::is_same_v<T, Duration>) {
            return std::to_string(value.count());
        }
        else if constexpr (std::is_convertible_v<T, std::string>) {
            return static_cast<std::string>(value);
        }
        else if constexpr (std::is_arithmetic_v<T>) {
            return std::to_string(value);
        }
        else {
            static_assert(always_false_v<T>, "Unsupported type for toString");
            VL_THROW("Cannot convert type {} to string", typeid(T).name()); // prevent -wreturn
        }
    }

    template<typename T>
    T fromString(const std::string& str) {
        if constexpr (IsVlEnum<T>) {
            return _fromString<T>(str);
        }
        else if constexpr (std::is_same_v<T, TimePoint>) {
            using namespace std::chrono;

            std::tm tm{};
            char sep;
            double fractional_seconds = 0.0;

            std::istringstream iss(str);
            iss >> std::get_time(&tm, STRING_FORMAT.data());

            if (!iss)
                throw std::invalid_argument("Invalid time format");

            // Read fractional part if present
            if (iss.peek() == '.')
            {
                iss >> sep >> fractional_seconds;
            }

#if defined(VL_PLATFORM_WINDOWS)
            std::time_t tt = _mkgmtime(&tm); // UTC
#else
            std::time_t tt = timegm(&tm);    // UTC
#endif

            if (tt == -1)
                throw std::invalid_argument("Invalid time value");

            TimePoint tp = time_point_cast<Duration>(system_clock::from_time_t(tt));

            tp += Duration{fractional_seconds};
            return tp;
        }
        else if constexpr (std::is_same_v<T, Duration>) {
            return Duration(std::stod(str));
        }
        else if constexpr (std::is_convertible_v<T, std::string>) {
            return static_cast<T>(str);
        }
        else if constexpr (std::is_integral_v<T>) {
            return static_cast<T>(std::stoll(str));
        }
        else if constexpr (std::is_floating_point_v<T>) {
            return static_cast<T>(std::stod(str));
        }
        else {
            static_assert(always_false_v<T>, "Unsupported type for fromString");
            VL_THROW("Cannot convert string to type {}", typeid(T).name()); // prevent -wreturn
        }
    }

}