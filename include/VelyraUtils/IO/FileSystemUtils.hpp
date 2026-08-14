#pragma once

#include <nlohmann/json_fwd.hpp>
#include <optional>
#include <VelyraUtils/IO/IncludeFileSystem.hpp>

namespace Velyra::Utils::IO {

    std::optional<nlohmann::json> readJson(const fs::path& path);

}