#include <VelyraUtils/CpuFeatures.hpp>

#if defined(VL_COMPILER_MSVC)
    #include <intrin.h>
#elif defined(VL_COMPILER_GCC) || defined(VL_COMPILER_CLANG)
    #include <cpuid.h>
#endif

namespace Velyra::Utils {

    CpuFeatures detectCpuFeatures() {
        CpuFeatures features;

#if defined(VL_COMPILER_MSVC)
        int cpuInfo[4];
        __cpuid(cpuInfo, 1);
        features.sse2 = cpuInfo[3] & (1 << 26);
        features.avx  = cpuInfo[2] & (1 << 28);

        __cpuid(cpuInfo, 7);
        features.avx2 = cpuInfo[1] & (1 << 5);

#elif defined(VL_COMPILER_GCC) || defined(VL_COMPILER_CLANG)
        unsigned int eax, ebx, ecx, edx;

        // Leaf 1
        __cpuid(1, eax, ebx, ecx, edx);
        features.sse2 = edx & (1 << 26);
        features.avx  = ecx & (1 << 28);

        // Leaf 7
        __cpuid_count(7, 0, eax, ebx, ecx, edx);
        features.avx2 = ebx & (1 << 5);
#endif
        return features;
    }

}
