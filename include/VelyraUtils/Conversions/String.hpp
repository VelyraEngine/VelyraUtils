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
            // Convert high_resolution_clock::time_point -> system_clock::time_point
            auto sys_duration = std::chrono::duration_cast<std::chrono::system_clock::duration>(
                value.time_since_epoch()
            );
            std::chrono::system_clock::time_point sys_tp(sys_duration);

            // Convert to time_t for formatting
            std::time_t tt = std::chrono::system_clock::to_time_t(sys_tp);

            // Convert to UTC tm
            std::tm tm{};
#if defined(_WIN32)
            gmtime_s(&tm, &tt);  // Windows
#else
            gmtime_r(&tt, &tm);  // POSIX
#endif

            // Format string
            char buf[64];
            std::strftime(buf, sizeof(buf), STRING_FORMAT.data(), &tm);

            return std::string(buf);
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
            std::tm time_info = {};
            std::istringstream ss(str);
            ss >> std::get_time(&time_info, STRING_FORMAT.data());
            if (ss.fail()) {
                VL_THROW("Invalid time format: {}. Expected format: {}", str, STRING_FORMAT);
            }
            const std::time_t tt = timegm(&time_info); // Parsed in Universal Time
            return TimePoint(std::chrono::duration_cast<TimePoint::duration>(std::chrono::system_clock::from_time_t(tt).time_since_epoch()));
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