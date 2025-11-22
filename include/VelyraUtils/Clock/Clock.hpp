#pragma once

#include <VelyraUtils/Types/Types.hpp>

#include <chrono>

namespace Velyra {

    using namespace std::chrono_literals;

    using Duration = std::chrono::duration<double, std::milli>;
    using TimePoint = std::chrono::time_point<std::chrono::high_resolution_clock, Duration>;
    using SystemTimePoint = std::chrono::system_clock::time_point;
    using SystemDuration = std::chrono::system_clock::duration;

    inline TimePoint getTime(){
        return std::chrono::high_resolution_clock::now();
    }

    inline SystemTimePoint getSystemTime() {
        return std::chrono::system_clock::now();
    }

    inline TimePoint timeFromEpoch(const U64 time) {
        return TimePoint(Duration{static_cast<double>(time)});
    }

    inline TimePoint timeFromEpoch(const double time) {
        return TimePoint(Duration{time});
    }
}