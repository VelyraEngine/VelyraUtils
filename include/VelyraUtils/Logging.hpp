#pragma once

#include <spdlog/spdlog.h>

namespace Velyra::Utils {

    using LogPtr = std::shared_ptr<spdlog::logger>;

    LogPtr getLogger(const std::string& name);

}

