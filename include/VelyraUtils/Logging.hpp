#pragma once

#include <memory>
#include <spdlog/fwd.h>

namespace Velyra::Utils {

    using LogPtr = std::shared_ptr<spdlog::logger>;

    LogPtr getLogger(const std::string& name);

}

