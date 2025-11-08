#pragma once

#include <VelyraUtils/PlatformDetection.hpp>

#if defined(VL_COMPILER_MSVC)
    #if defined(VL_DLL_IMPORT)
        #define VL_API __declspec(dllimport)
    #else
        #define VL_API __declspec(dllexport)
    #endif
#elif defined(VL_COMPILER_GCC)
    #if __GNUC__ >= 4
        #define VL_API __attribute__((visibility("default")))
    #else
        #define VL_API
    #endif
#else
    #define VL_API
#endif