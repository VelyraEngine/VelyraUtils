#pragma once

// Define OS-specific macro's
#if defined(WIN64) || defined(_WIN64) || defined(WIN32)
    #define VL_PLATFORM_WINDOWS

#elif defined(__linux__)
    #define VL_PLATFORM_LINUX

#else
    #error "Platform not supported"
#endif

// Define toolchain macro's
#if defined(_MSC_VER)
    #define VL_COMPILER_MSVC

    #define VL_FILE __FILE__
    #define VL_LINE __LINE__
    #define VL_FUNC __FUNCSIG__

#elif defined(__GNUC__)
    #define VL_COMPILER_GCC

    #define VL_FILE __FILE__
    #define VL_LINE __LINE__
    #define VL_FUNC __PRETTY_FUNCTION__

#elif defined(__clang__)
    #define VL_COMPILER_CLANG

    #define VL_FILE __FILE__
    #define VL_LINE __LINE__
    #define VL_FUNC __PRETTY_FUNCTION__

#else
    #error "Compiler is not supported"
#endif