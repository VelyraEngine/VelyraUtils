#include <VelyraUtils/Logging.hpp>

#include <spdlog/sinks/stdout_sinks.h>

namespace Velyra::Utils {

    LogPtr getLogger(const std::string& name) {
        LogPtr logger = spdlog::get(name);
        if (!logger) {
            auto console_sink = std::make_shared<spdlog::sinks::stdout_sink_mt>();
            console_sink->set_pattern("[%n] [%l] [%s:%!:%#] %v");  // <- works here
            logger = std::make_shared<spdlog::logger>(name, console_sink);
            spdlog::register_logger(logger);
        }
        return logger;
    }

}