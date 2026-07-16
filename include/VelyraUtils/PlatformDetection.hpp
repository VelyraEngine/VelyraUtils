#pragma once

// Architecture
#if defined(__x86_64__) || defined(_M_X64)
    #define VL_ARCH_X86_64

#elif defined(__i386__) || defined(_M_IX86)
    #define VL_ARCH_X86

#elif defined(__aarch64__) || defined(_M_ARM64)
    #define VL_ARCH_ARM64

#elif defined(__arm__) || defined(_M_ARM)
    #define VL_ARCH_ARM32

#else
    #error "Unknown architecture"
#endif


// Bitness
#if defined(_WIN64) || defined(__LP64__) || defined(_LP64)
    #define VL_ARCH_64BIT

#elif defined(_WIN32) || defined(__ILP32__)
    #define VL_ARCH_32BIT

#else
    static_assert(sizeof(void*) == 4 || sizeof(void*) == 8,
                  "Unknown pointer size");

    #if INTPTR_MAX == INT64_MAX
        #define VL_ARCH_64BIT
    #elif INTPTR_MAX == INT32_MAX
        #define VL_ARCH_32BIT
    #else
        #error "Unknown pointer size"
    #endif
#endif

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