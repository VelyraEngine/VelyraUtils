#pragma once

#include <cmath>

#if !defined(M_PI)
#define M_PI 3.14159265358979323846
#define M_PI_2 1.57079632679489661923
#endif

namespace Velyra::Utils {

    template<typename T>
    inline bool almostEqual(T a, T b, T epsilon = static_cast<T>(1e-5)){
        if constexpr (std::is_floating_point_v<T>) {
            return std::fabs(a - b) <= epsilon;
        }
        else {
            return a == b;
        }
    }

}