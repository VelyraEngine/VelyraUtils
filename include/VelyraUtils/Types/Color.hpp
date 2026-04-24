#pragma once

#include <VelyraUtils/PlatformDetection.hpp>
#include <VelyraUtils/Math.hpp>

namespace Velyra::Utils {

    struct VL_API Color {
        float r = 0.0f;
        float g = 0.0f;
        float b = 0.0f;
        float a = 1.0f;

        Color() = default;

        Color(const float r_, const float g_, const float b_,
              const float a_ = 1.0f):
        r(r_), g(g_), b(b_), a(a_){}

        float* toArray() { return &r; }

        [[nodiscard]] const float* toArray() const { return &r; }

        bool operator==(const Color& other) const {
            return almostEqual(r, other.r) &&
                almostEqual(g, other.g) &&
                almostEqual(b, other.b) &&
                almostEqual(a, other.a);
        }

        bool operator!=(const Color &other) const {
            return !(*this == other);
        }
    };

}