#pragma once

#include <spdlog/spdlog.h>
#include <VelyraUtils/Logging/Formatters.hpp>
#include <VelyraUtils/Logging/LoggingFwd.hpp>

namespace Velyra::Utils {

    using LogPtr = std::shared_ptr<spdlog::logger>;

    LogPtr getLogger(const std::string& name);

}

#if defined(SPDLOG_LOGGER_WARN)

#define SPDLOG_LOGGER_PERFORMANCE(logger, ...) SPDLOG_LOGGER_WARN(logger, "[PERFORMANCE]: " __VA_ARGS__)

#else

#define SPDLOG_LOGGER_PERFORMANCE(logger, ...) (void)0

#endif

