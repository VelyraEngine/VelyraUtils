#pragma once

#include <VelyraUtils/Types/Types.hpp>

namespace Velyra::Utils {

#pragma pack(push, 1)

    struct VL_API Color {
        float r = 0.0f;
        float g = 0.0f;
        float b = 0.0f;
        float a = 1.0f;

        Color() = default;

        Color(float r_, float g_, float b_, float a_ = 1.0f);

        float* toArray() { return &r; }

        [[nodiscard]] const float* toArray() const { return &r; }
    };

#pragma pack(pop)

}