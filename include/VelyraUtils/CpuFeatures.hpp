#pragma once

#include <VelyraUtils/ExportUtils.hpp>

namespace Velyra::Utils {

    struct VL_API CpuFeatures {
        bool sse2 = false;
        bool avx  = false;
        bool avx2 = false;
    };

    VL_API CpuFeatures detectCpuFeatures();
}