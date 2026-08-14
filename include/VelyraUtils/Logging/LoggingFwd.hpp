#pragma once

#include <memory>

namespace spdlog {
    class logger;
}

namespace Velyra::Utils {

    using LogPtr = std::shared_ptr<spdlog::logger>;

    LogPtr getLogger(const std::string& name);

}