#pragma once

#include <VelyraUtils/PlatformDetection.hpp>
#include <spdlog/fmt/bundled/format.h>
#include <spdlog/fmt/bundled/printf.h>
#include <string>

namespace Velyra::Utils::Detail {

    template<typename... Args>
    void formatCondition(
        const char* conditionType,
        const char* condition,
        const char* file,
        const char* function,
        int line,
        fmt::string_view msg,
        Args&&... args) {
        std::string formatted = fmt::format(fmt::runtime(msg), std::forward<Args>(args)...);

        fmt::print("[{} TRIGGERED] [{} : {} : {}]: Condition: {} | Message: {}\n",
            conditionType, file, line, function, condition, formatted);

        fflush(stdout);
        std::abort();
    }

}

#if defined(VL_DEBUG) || defined(VL_TESTING)

#define VL_INTERNAL_ASSERT(conditionType, condition, msg, ...)             \
    do {                                                                   \
        if (!(condition)) {                                                \
            Velyra::Utils::Detail::formatCondition(                        \
                conditionType, #condition, VL_FILE, VL_FUNC, VL_LINE,      \
                fmt::string_view(msg), ##__VA_ARGS__);                     \
        }                                                                  \
    } while (false)

#define VL_ASSERT(condition, msg, ...) VL_INTERNAL_ASSERT("ASSERT", condition, msg, ##__VA_ARGS__)
#define VL_PRECONDITION(condition, msg, ...) VL_INTERNAL_ASSERT("PRECONDITION", condition, msg, ##__VA_ARGS__)
#define VL_POSTCONDITION(condition, msg, ...) VL_INTERNAL_ASSERT("POSTCONDITION", condition, msg, ##__VA_ARGS__)

#else

#define VL_ASSERT(condition, msg, ...)
#define VL_PRECONDITION(condition, msg, ...)
#define VL_POSTCONDITION(condition, msg, ...)

#endif

#define VL_THROW(msg, ...) throw std::runtime_error(fmt::format(fmt::runtime(msg), ##__VA_ARGS__))