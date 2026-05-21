#pragma once

#include <VelyraUtils/Types/Types.hpp>

#include <chrono>

namespace Velyra {

    using namespace std::chrono_literals;

    static constexpr std::string_view STRING_FORMAT = "%Y-%m-%dT%H:%M:%S";

    using Duration = std::chrono::duration<double>;
    using TimePoint = std::chrono::time_point<std::chrono::system_clock, Duration>;

    inline TimePoint getTime(){
        return std::chrono::system_clock::now();
    }

    inline TimePoint timeFromEpoch(const U64 time) {
        return TimePoint(Duration{static_cast<double>(time)});
    }

    inline TimePoint timeFromEpoch(const double time) {
        return TimePoint(Duration{time});
    }
}