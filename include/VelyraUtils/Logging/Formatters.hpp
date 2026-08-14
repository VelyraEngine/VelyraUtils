#pragma once

#include <VelyraUtils/IO/IncludeFileSystem.hpp>
#include <VelyraUtils/DevUtils/Fmt.hpp>

template<>
struct fmt::formatter<std::filesystem::path> {
    constexpr auto parse(fmt::format_parse_context& ctx) -> decltype(ctx.begin()) {
        return ctx.begin();
    }

    template <typename FormatContext>
    auto format(const std::filesystem::path& p, FormatContext& ctx) const -> decltype(ctx.out()) {
        return fmt::format_to(ctx.out(), "{}", p.string());
    }
};

