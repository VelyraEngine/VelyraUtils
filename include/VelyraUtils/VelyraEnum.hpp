#pragma once

#include <string>
#include <stdexcept>
#include <unordered_map>
#include <exception>
#include <vector>
#include <type_traits>
#include <spdlog/fmt/bundled/core.h>
#include <spdlog/fmt/bundled/format.h>

#define VA_COUNT_IMPL( \
_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, \
_11,_12,_13,_14,_15,_16,_17,_18,_19,_20, \
_21,_22,_23,_24,_25,_26,_27,_28,_29,_30, \
_31,_32,_33,_34,_35,_36,_37,_38,_39,_40, \
_41,_42,_43,_44,_45,_46,_47,_48,_49,_50, \
_51,_52,_53,_54,_55,_56,_57,_58,_59,_60, \
_61,_62,_63,N,...) N

#define VA_COUNT(...) VA_COUNT_IMPL(__VA_ARGS__, \
63,62,61,60,                   \
59,58,57,56,55,54,53,52,51,50,\
49,48,47,46,45,44,43,42,41,40,\
39,38,37,36,35,34,33,32,31,30,\
29,28,27,26,25,24,23,22,21,20,\
19,18,17,16,15,14,13,12,11,10,\
9,8,7,6,5,4,3,2,1,0)


#define VL_ENUM_PP_MAP(macro, data, ...)                         \
    VL_ENUM_ID(VL_ENUM_APPLY(VL_ENUM_PP_MVL_VAR_COUNT, \
                                       VL_ENUM_PP_COUNT(__VA_ARGS__))(macro, data, __VA_ARGS__))

#define VL_ENUM_PP_MVL_VAR_COUNT(count) VL_ENUM_M##count

#define VL_ENUM_APPLY(macro, ...) VL_ENUM_ID(macro(__VA_ARGS__))

#define VL_ENUM_ID(x) x

#define VL_ENUM_M1(m, d, x) m(d, 0, x)
#define VL_ENUM_M2(m, d, x, ...) m(d, 1, x) VL_ENUM_ID(VL_ENUM_M1(m, d, __VA_ARGS__))
#define VL_ENUM_M3(m, d, x, ...) m(d, 2, x) VL_ENUM_ID(VL_ENUM_M2(m, d, __VA_ARGS__))
#define VL_ENUM_M4(m, d, x, ...) m(d, 3, x) VL_ENUM_ID(VL_ENUM_M3(m, d, __VA_ARGS__))
#define VL_ENUM_M5(m, d, x, ...) m(d, 4, x) VL_ENUM_ID(VL_ENUM_M4(m, d, __VA_ARGS__))
#define VL_ENUM_M6(m, d, x, ...) m(d, 5, x) VL_ENUM_ID(VL_ENUM_M5(m, d, __VA_ARGS__))
#define VL_ENUM_M7(m, d, x, ...) m(d, 6, x) VL_ENUM_ID(VL_ENUM_M6(m, d, __VA_ARGS__))
#define VL_ENUM_M8(m, d, x, ...) m(d, 7, x) VL_ENUM_ID(VL_ENUM_M7(m, d, __VA_ARGS__))
#define VL_ENUM_M9(m, d, x, ...) m(d, 8, x) VL_ENUM_ID(VL_ENUM_M8(m, d, __VA_ARGS__))
#define VL_ENUM_M10(m, d, x, ...) m(d, 9, x) VL_ENUM_ID(VL_ENUM_M9(m, d, __VA_ARGS__))
#define VL_ENUM_M11(m, d, x, ...) m(d, 10, x) VL_ENUM_ID(VL_ENUM_M10(m, d, __VA_ARGS__))
#define VL_ENUM_M12(m, d, x, ...) m(d, 11, x) VL_ENUM_ID(VL_ENUM_M11(m, d, __VA_ARGS__))
#define VL_ENUM_M13(m, d, x, ...) m(d, 12, x) VL_ENUM_ID(VL_ENUM_M12(m, d, __VA_ARGS__))
#define VL_ENUM_M14(m, d, x, ...) m(d, 13, x) VL_ENUM_ID(VL_ENUM_M13(m, d, __VA_ARGS__))
#define VL_ENUM_M15(m, d, x, ...) m(d, 14, x) VL_ENUM_ID(VL_ENUM_M14(m, d, __VA_ARGS__))
#define VL_ENUM_M16(m, d, x, ...) m(d, 15, x) VL_ENUM_ID(VL_ENUM_M15(m, d, __VA_ARGS__))
#define VL_ENUM_M17(m, d, x, ...) m(d, 16, x) VL_ENUM_ID(VL_ENUM_M16(m, d, __VA_ARGS__))
#define VL_ENUM_M18(m, d, x, ...) m(d, 17, x) VL_ENUM_ID(VL_ENUM_M17(m, d, __VA_ARGS__))
#define VL_ENUM_M19(m, d, x, ...) m(d, 18, x) VL_ENUM_ID(VL_ENUM_M18(m, d, __VA_ARGS__))
#define VL_ENUM_M20(m, d, x, ...) m(d, 19, x) VL_ENUM_ID(VL_ENUM_M19(m, d, __VA_ARGS__))
#define VL_ENUM_M21(m, d, x, ...) m(d, 20, x) VL_ENUM_ID(VL_ENUM_M20(m, d, __VA_ARGS__))
#define VL_ENUM_M22(m, d, x, ...) m(d, 21, x) VL_ENUM_ID(VL_ENUM_M21(m, d, __VA_ARGS__))
#define VL_ENUM_M23(m, d, x, ...) m(d, 22, x) VL_ENUM_ID(VL_ENUM_M22(m, d, __VA_ARGS__))
#define VL_ENUM_M24(m, d, x, ...) m(d, 23, x) VL_ENUM_ID(VL_ENUM_M23(m, d, __VA_ARGS__))
#define VL_ENUM_M25(m, d, x, ...) m(d, 24, x) VL_ENUM_ID(VL_ENUM_M24(m, d, __VA_ARGS__))
#define VL_ENUM_M26(m, d, x, ...) m(d, 25, x) VL_ENUM_ID(VL_ENUM_M25(m, d, __VA_ARGS__))
#define VL_ENUM_M27(m, d, x, ...) m(d, 26, x) VL_ENUM_ID(VL_ENUM_M26(m, d, __VA_ARGS__))
#define VL_ENUM_M28(m, d, x, ...) m(d, 27, x) VL_ENUM_ID(VL_ENUM_M27(m, d, __VA_ARGS__))
#define VL_ENUM_M29(m, d, x, ...) m(d, 28, x) VL_ENUM_ID(VL_ENUM_M28(m, d, __VA_ARGS__))
#define VL_ENUM_M30(m, d, x, ...) m(d, 29, x) VL_ENUM_ID(VL_ENUM_M29(m, d, __VA_ARGS__))
#define VL_ENUM_M31(m, d, x, ...) m(d, 30, x) VL_ENUM_ID(VL_ENUM_M30(m, d, __VA_ARGS__))
#define VL_ENUM_M32(m, d, x, ...) m(d, 31, x) VL_ENUM_ID(VL_ENUM_M31(m, d, __VA_ARGS__))
#define VL_ENUM_M33(m, d, x, ...) m(d, 32, x) VL_ENUM_ID(VL_ENUM_M32(m, d, __VA_ARGS__))
#define VL_ENUM_M34(m, d, x, ...) m(d, 33, x) VL_ENUM_ID(VL_ENUM_M33(m, d, __VA_ARGS__))
#define VL_ENUM_M35(m, d, x, ...) m(d, 34, x) VL_ENUM_ID(VL_ENUM_M34(m, d, __VA_ARGS__))
#define VL_ENUM_M36(m, d, x, ...) m(d, 35, x) VL_ENUM_ID(VL_ENUM_M35(m, d, __VA_ARGS__))
#define VL_ENUM_M37(m, d, x, ...) m(d, 36, x) VL_ENUM_ID(VL_ENUM_M36(m, d, __VA_ARGS__))
#define VL_ENUM_M38(m, d, x, ...) m(d, 37, x) VL_ENUM_ID(VL_ENUM_M37(m, d, __VA_ARGS__))
#define VL_ENUM_M39(m, d, x, ...) m(d, 38, x) VL_ENUM_ID(VL_ENUM_M38(m, d, __VA_ARGS__))
#define VL_ENUM_M40(m, d, x, ...) m(d, 39, x) VL_ENUM_ID(VL_ENUM_M39(m, d, __VA_ARGS__))
#define VL_ENUM_M41(m, d, x, ...) m(d, 40, x) VL_ENUM_ID(VL_ENUM_M40(m, d, __VA_ARGS__))
#define VL_ENUM_M42(m, d, x, ...) m(d, 41, x) VL_ENUM_ID(VL_ENUM_M41(m, d, __VA_ARGS__))
#define VL_ENUM_M43(m, d, x, ...) m(d, 42, x) VL_ENUM_ID(VL_ENUM_M42(m, d, __VA_ARGS__))
#define VL_ENUM_M44(m, d, x, ...) m(d, 43, x) VL_ENUM_ID(VL_ENUM_M43(m, d, __VA_ARGS__))
#define VL_ENUM_M45(m, d, x, ...) m(d, 44, x) VL_ENUM_ID(VL_ENUM_M44(m, d, __VA_ARGS__))
#define VL_ENUM_M46(m, d, x, ...) m(d, 45, x) VL_ENUM_ID(VL_ENUM_M45(m, d, __VA_ARGS__))
#define VL_ENUM_M47(m, d, x, ...) m(d, 46, x) VL_ENUM_ID(VL_ENUM_M46(m, d, __VA_ARGS__))
#define VL_ENUM_M48(m, d, x, ...) m(d, 47, x) VL_ENUM_ID(VL_ENUM_M47(m, d, __VA_ARGS__))
#define VL_ENUM_M49(m, d, x, ...) m(d, 48, x) VL_ENUM_ID(VL_ENUM_M48(m, d, __VA_ARGS__))
#define VL_ENUM_M50(m, d, x, ...) m(d, 49, x) VL_ENUM_ID(VL_ENUM_M49(m, d, __VA_ARGS__))
#define VL_ENUM_M51(m, d, x, ...) m(d, 50, x) VL_ENUM_ID(VL_ENUM_M50(m, d, __VA_ARGS__))
#define VL_ENUM_M52(m, d, x, ...) m(d, 51, x) VL_ENUM_ID(VL_ENUM_M51(m, d, __VA_ARGS__))
#define VL_ENUM_M53(m, d, x, ...) m(d, 52, x) VL_ENUM_ID(VL_ENUM_M52(m, d, __VA_ARGS__))
#define VL_ENUM_M54(m, d, x, ...) m(d, 53, x) VL_ENUM_ID(VL_ENUM_M53(m, d, __VA_ARGS__))
#define VL_ENUM_M55(m, d, x, ...) m(d, 54, x) VL_ENUM_ID(VL_ENUM_M54(m, d, __VA_ARGS__))
#define VL_ENUM_M56(m, d, x, ...) m(d, 55, x) VL_ENUM_ID(VL_ENUM_M55(m, d, __VA_ARGS__))
#define VL_ENUM_M57(m, d, x, ...) m(d, 56, x) VL_ENUM_ID(VL_ENUM_M56(m, d, __VA_ARGS__))
#define VL_ENUM_M58(m, d, x, ...) m(d, 57, x) VL_ENUM_ID(VL_ENUM_M57(m, d, __VA_ARGS__))
#define VL_ENUM_M59(m, d, x, ...) m(d, 58, x) VL_ENUM_ID(VL_ENUM_M58(m, d, __VA_ARGS__))
#define VL_ENUM_M60(m, d, x, ...) m(d, 59, x) VL_ENUM_ID(VL_ENUM_M59(m, d, __VA_ARGS__))
#define VL_ENUM_M61(m, d, x, ...) m(d, 60, x) VL_ENUM_ID(VL_ENUM_M60(m, d, __VA_ARGS__))
#define VL_ENUM_M62(m, d, x, ...) m(d, 61, x) VL_ENUM_ID(VL_ENUM_M61(m, d, __VA_ARGS__))
#define VL_ENUM_M63(m, d, x, ...) m(d, 62, x) VL_ENUM_ID(VL_ENUM_M62(m, d, __VA_ARGS__))
#define VL_ENUM_M64(m, d, x, ...) m(d, 63, x) VL_ENUM_ID(VL_ENUM_M63(m, d, __VA_ARGS__))

#define VL_ENUM_PP_COUNT_IMPL(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, count, ...) count

#define VL_ENUM_PP_COUNT(...)                                                                                     \
    VL_ENUM_ID(VL_ENUM_PP_COUNT_IMPL(__VA_ARGS__, 64, 63, 62, 61, 60, 59, 58, 57, 56, 55, 54, 53, 52, 51, 50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1))

template<typename T>
struct is_vl_enum: std::false_type {};

template<typename T>
T fromString(const std::string& value){
    static_assert(is_vl_enum<T>::value, "Type is not an VL_ENUM");
    throw std::runtime_error("fromString not implemented for this type");
}

namespace ap::detail {
    /** Get intrinsic value of an (Enum::value) by taking advantage of
     * C-conversion's parentheses priority
     */
    template<typename EnumType>
    struct _eat_assign {
        explicit constexpr _eat_assign(EnumType value) : _value(value) {}

        template<typename Any>
        constexpr const _eat_assign &operator=(Any) const
        {
            return *this;
        }

        explicit constexpr operator EnumType() const { return _value; }

    private:
        EnumType _value;
    };

    inline std::string getEnumValue(const std::string& full_expansion) {
        std::string_view view = full_expansion;

        // Find the position of '='
        auto pos = view.find('=');
        if (pos != std::string_view::npos) {
            // Trim whitespace before '='
            view = view.substr(0, pos);

            // Trim trailing whitespace
            size_t end = view.find_last_not_of(" \t");
            if (end != std::string_view::npos) {
                view = view.substr(0, end + 1);
            }
        }

        return std::string(view);
    }

}

#define VL_ENUM_VALUE_COUNT_NAME _ValueCount

#define VL_ENUM_ADD_ENTRY(EnumType, idx, expression) expression,
#define VL_ENUM_ADD_VALUE(EnumType, idx, expression) \
    (EnumType)((ap::detail::_eat_assign<EnumType>)EnumType::expression),
#define VL_ENUM_VALUE_STRING(EnumType, idx, expression) \
    #expression,

#define VL_ENUM_BUILD_STRING(expression) #expression

#define VL_ENUM_VALUE_ARRAY_NAME _Values
#define VL_ENUM_RAW_NAMES_ARRAY_NAME _RawNames
#define VL_ENUM_MVL_VALUE_TO_STR _ValueToStr
#define VL_ENUM_MVL_STR_TO_VALUE _StrToValue

/**
 * @brief Macro to generate an enum with fromString and toString function. This code is heavily inspired by
 *        BETTER_ENUM.
 *        This will expand in a typedef enum, a to_string function and a from_string function.
 *        The choice to make it a typedef enum instead of enum class is to allow bitwise operations.
 * @param Name
 * @param Type
 */
#define VL_ENUM(Name, Type, ...) \
    typedef enum Name: Type { \
        VL_ENUM_ID(VL_ENUM_PP_MAP(VL_ENUM_ADD_ENTRY, Name, __VA_ARGS__)) \
        Name##_MAX_VALUE \
    } Name; \
    template<>\
    struct is_vl_enum<Name>: std::true_type {}; \
    namespace Name##_detail{ \
        constexpr std::size_t VL_ENUM_VALUE_COUNT_NAME = VA_COUNT(__VA_ARGS__); \
        constexpr Name VL_ENUM_VALUE_ARRAY_NAME[] = { \
            VL_ENUM_ID(VL_ENUM_PP_MAP(VL_ENUM_ADD_VALUE, Name, __VA_ARGS__)) \
        };\
        static std::vector<std::string> VL_ENUM_RAW_NAMES_ARRAY_NAME = { \
            VL_ENUM_ID(VL_ENUM_PP_MAP(VL_ENUM_VALUE_STRING, Name, __VA_ARGS__)) \
        }; \
        static bool Name##_StructuresGenerated = false; \
        static std::unordered_map<Name, std::string> VL_ENUM_MVL_VALUE_TO_STR; \
        static std::unordered_map<std::string, Name> VL_ENUM_MVL_STR_TO_VALUE; \
        static void generateStructures(){ \
            for (std::size_t idx = 0; idx < VL_ENUM_VALUE_COUNT_NAME; idx++){ \
                Name value = VL_ENUM_VALUE_ARRAY_NAME[idx]; \
                std::string value_str = ap::detail::getEnumValue(VL_ENUM_RAW_NAMES_ARRAY_NAME[idx]); \
                VL_ENUM_MVL_VALUE_TO_STR.insert({value, value_str}); \
                VL_ENUM_MVL_STR_TO_VALUE.insert({value_str, value}); \
            } \
            VL_ENUM_MVL_VALUE_TO_STR.insert({Name##_MAX_VALUE, VL_ENUM_BUILD_STRING(Name##_MAX_VALUE)}); \
            VL_ENUM_MVL_STR_TO_VALUE.insert({VL_ENUM_BUILD_STRING(Name##_MAX_VALUE), Name##_MAX_VALUE}); \
            Name##_StructuresGenerated = true; \
        } \
    } \
    inline std::string toString(Name value){ \
        if (!Name##_detail::Name##_StructuresGenerated){ \
            Name##_detail::generateStructures(); \
        } \
        auto it = Name##_detail::VL_ENUM_MVL_VALUE_TO_STR.find(value); \
        if (it == Name##_detail::VL_ENUM_MVL_VALUE_TO_STR.end()){ \
            return {}; \
        } \
        return it->second; \
    } \
    template<> \
    inline Name fromString<Name>(const std::string& value){ \
        if (!Name##_detail::Name##_StructuresGenerated){ \
            Name##_detail::generateStructures(); \
        } \
        auto it = Name##_detail::VL_ENUM_MVL_STR_TO_VALUE.find(value); \
        if (it == Name##_detail::VL_ENUM_MVL_STR_TO_VALUE.end()){ \
            return Name##_MAX_VALUE; \
        } \
        return it->second; \
    } \
    template<> \
    struct fmt::formatter<Name> { \
        constexpr auto parse(fmt::format_parse_context& ctx) -> decltype(ctx.begin()) { \
            return ctx.begin();  \
        } \
        template <typename FormatContext> \
        auto format(const Name& p, FormatContext& ctx) const -> decltype(ctx.out()) { \
            return fmt::format_to(ctx.out(), "{}", toString(p)); \
        } \
    }
