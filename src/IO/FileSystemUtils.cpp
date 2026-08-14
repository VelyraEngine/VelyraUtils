#include <VelyraUtils/IO/FileSystemUtils.hpp>

#include <nlohmann/json.hpp>

#include <VelyraUtils/Logging/Logging.hpp>
#include <fstream>

namespace Velyra::Utils::IO {

    std::optional<nlohmann::json> readJson(const fs::path& path) {
        const LogPtr logger = getLogger("VL-IO");

        if (!fs::exists(path) || !fs::is_regular_file(path)) {
            SPDLOG_LOGGER_ERROR(logger, "File does not exist or is not a regular file: {}", path.string());
            return std::nullopt;
        }
        std::ifstream file(path);
        if (!file.is_open()) {
            SPDLOG_LOGGER_ERROR(logger, "Failed to open file: {}", path.string());
            return std::nullopt;
        }
        try {
            return nlohmann::json::parse(file);
        } catch (const nlohmann::json::parse_error& e) {
            SPDLOG_LOGGER_ERROR(logger, "Failed to parse JSON from file '{}': {}", path.string(), e.what());
            return std::nullopt;
        }
    }

}