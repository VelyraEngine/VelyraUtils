#include <VelyraUtils/Logging.hpp>

#include <spdlog/sinks/stdout_sinks.h>
#include <VelyraUtils/Types/Types.hpp>

namespace Velyra::Utils {

    LogPtr getLogger(const std::string& name) {
        LogPtr logger = spdlog::get(name);
        if (!logger) {
            auto console_sink = std::make_shared<spdlog::sinks::stdout_sink_mt>();
            console_sink->set_pattern("[%n] [%l] [%s:%!:%#] %v");  // <- works here
            logger = std::make_shared<spdlog::logger>(name, console_sink);

#if defined(VL_DEBUG)
            logger->set_level(spdlog::level::trace);
#else
            logger->set_level(spdlog::level::err);
    #endif

            spdlog::register_logger(logger);
        }
        return logger;
    }

}
