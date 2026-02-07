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
_1,_2,_3,_4,_5,_6,_7,_8,_9,_10, \
_11,_12,_13,_14,_15,_16,_17,_18,_19,_20, \
_21,_22,_23,_24,_25,_26,_27,_28,_29,_30, \
_31,_32,_33,_34,_35,_36,_37,_38,_39,_40, \
_41,_42,_43,_44,_45,_46,_47,_48,_49,_50, \
_51,_52,_53,_54,_55,_56,_57,_58,_59,_60, \
_61,_62,_63,_64,_65,_66,_67,_68,_69,_70, \
_71,_72,_73,_74,_75,_76,_77,_78,_79,_80, \
_81,_82,_83,_84,_85,_86,_87,_88,_89,_90, \
_91,_92,_93,_94,_95,_96,_97,_98,_99,_100, \
_101,_102,_103,_104,_105,_106,_107,_108,_109,_110, \
_111,_112,_113,_114,_115,_116,_117,_118,_119,_120, \
_121,_122,_123,_124,_125,_126,_127,_128, N, ...) N

#define VA_COUNT(...) VA_COUNT_IMPL(__VA_ARGS__, \
128,127,126,125,124,123,122,121,120,119,118,117,116,115,114,113, \
112,111,110,109,108,107,106,105,104,103,102,101,100,99,98,97, \
96,95,94,93,92,91,90,89,88,87,86,85,84,83,82,81, \
80,79,78,77,76,75,74,73,72,71,70,69,68,67,66,65, \
64,63,62,61,60,59,58,57,56,55,54,53,52,51,50,49, \
48,47,46,45,44,43,42,41,40,39,38,37,36,35,34,33, \
32,31,30,29,28,27,26,25,24,23,22,21,20,19,18,17, \
16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0)


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
#define VL_ENUM_M65(m, d, x, ...) m(d, 64, x) VL_ENUM_ID(VL_ENUM_M64(m, d, __VA_ARGS__))
#define VL_ENUM_M66(m, d, x, ...) m(d, 65, x) VL_ENUM_ID(VL_ENUM_M65(m, d, __VA_ARGS__))
#define VL_ENUM_M67(m, d, x, ...) m(d, 66, x) VL_ENUM_ID(VL_ENUM_M66(m, d, __VA_ARGS__))
#define VL_ENUM_M68(m, d, x, ...) m(d, 67, x) VL_ENUM_ID(VL_ENUM_M67(m, d, __VA_ARGS__))
#define VL_ENUM_M69(m, d, x, ...) m(d, 68, x) VL_ENUM_ID(VL_ENUM_M68(m, d, __VA_ARGS__))
#define VL_ENUM_M70(m, d, x, ...) m(d, 69, x) VL_ENUM_ID(VL_ENUM_M69(m, d, __VA_ARGS__))
#define VL_ENUM_M71(m, d, x, ...) m(d, 70, x) VL_ENUM_ID(VL_ENUM_M70(m, d, __VA_ARGS__))
#define VL_ENUM_M72(m, d, x, ...) m(d, 71, x) VL_ENUM_ID(VL_ENUM_M71(m, d, __VA_ARGS__))
#define VL_ENUM_M73(m, d, x, ...) m(d, 72, x) VL_ENUM_ID(VL_ENUM_M72(m, d, __VA_ARGS__))
#define VL_ENUM_M74(m, d, x, ...) m(d, 73, x) VL_ENUM_ID(VL_ENUM_M73(m, d, __VA_ARGS__))
#define VL_ENUM_M75(m, d, x, ...) m(d, 74, x) VL_ENUM_ID(VL_ENUM_M74(m, d, __VA_ARGS__))
#define VL_ENUM_M76(m, d, x, ...) m(d, 75, x) VL_ENUM_ID(VL_ENUM_M75(m, d, __VA_ARGS__))
#define VL_ENUM_M77(m, d, x, ...) m(d, 76, x) VL_ENUM_ID(VL_ENUM_M76(m, d, __VA_ARGS__))
#define VL_ENUM_M78(m, d, x, ...) m(d, 77, x) VL_ENUM_ID(VL_ENUM_M77(m, d, __VA_ARGS__))
#define VL_ENUM_M79(m, d, x, ...) m(d, 78, x) VL_ENUM_ID(VL_ENUM_M78(m, d, __VA_ARGS__))
#define VL_ENUM_M80(m, d, x, ...) m(d, 79, x) VL_ENUM_ID(VL_ENUM_M79(m, d, __VA_ARGS__))
#define VL_ENUM_M81(m, d, x, ...) m(d, 80, x) VL_ENUM_ID(VL_ENUM_M80(m, d, __VA_ARGS__))
#define VL_ENUM_M82(m, d, x, ...) m(d, 81, x) VL_ENUM_ID(VL_ENUM_M81(m, d, __VA_ARGS__))
#define VL_ENUM_M83(m, d, x, ...) m(d, 82, x) VL_ENUM_ID(VL_ENUM_M82(m, d, __VA_ARGS__))
#define VL_ENUM_M84(m, d, x, ...) m(d, 83, x) VL_ENUM_ID(VL_ENUM_M83(m, d, __VA_ARGS__))
#define VL_ENUM_M85(m, d, x, ...) m(d, 84, x) VL_ENUM_ID(VL_ENUM_M84(m, d, __VA_ARGS__))
#define VL_ENUM_M86(m, d, x, ...) m(d, 85, x) VL_ENUM_ID(VL_ENUM_M85(m, d, __VA_ARGS__))
#define VL_ENUM_M87(m, d, x, ...) m(d, 86, x) VL_ENUM_ID(VL_ENUM_M86(m, d, __VA_ARGS__))
#define VL_ENUM_M88(m, d, x, ...) m(d, 87, x) VL_ENUM_ID(VL_ENUM_M87(m, d, __VA_ARGS__))
#define VL_ENUM_M89(m, d, x, ...) m(d, 88, x) VL_ENUM_ID(VL_ENUM_M88(m, d, __VA_ARGS__))
#define VL_ENUM_M90(m, d, x, ...) m(d, 89, x) VL_ENUM_ID(VL_ENUM_M89(m, d, __VA_ARGS__))
#define VL_ENUM_M91(m, d, x, ...) m(d, 90, x) VL_ENUM_ID(VL_ENUM_M90(m, d, __VA_ARGS__))
#define VL_ENUM_M92(m, d, x, ...) m(d, 91, x) VL_ENUM_ID(VL_ENUM_M91(m, d, __VA_ARGS__))
#define VL_ENUM_M93(m, d, x, ...) m(d, 92, x) VL_ENUM_ID(VL_ENUM_M92(m, d, __VA_ARGS__))
#define VL_ENUM_M94(m, d, x, ...) m(d, 93, x) VL_ENUM_ID(VL_ENUM_M93(m, d, __VA_ARGS__))
#define VL_ENUM_M95(m, d, x, ...) m(d, 94, x) VL_ENUM_ID(VL_ENUM_M94(m, d, __VA_ARGS__))
#define VL_ENUM_M96(m, d, x, ...) m(d, 95, x) VL_ENUM_ID(VL_ENUM_M95(m, d, __VA_ARGS__))
#define VL_ENUM_M97(m, d, x, ...) m(d, 96, x) VL_ENUM_ID(VL_ENUM_M96(m, d, __VA_ARGS__))
#define VL_ENUM_M98(m, d, x, ...) m(d, 97, x) VL_ENUM_ID(VL_ENUM_M97(m, d, __VA_ARGS__))
#define VL_ENUM_M99(m, d, x, ...) m(d, 98, x) VL_ENUM_ID(VL_ENUM_M98(m, d, __VA_ARGS__))
#define VL_ENUM_M100(m, d, x, ...) m(d, 99, x) VL_ENUM_ID(VL_ENUM_M99(m, d, __VA_ARGS__))
#define VL_ENUM_M101(m, d, x, ...) m(d, 100, x) VL_ENUM_ID(VL_ENUM_M100(m, d, __VA_ARGS__))
#define VL_ENUM_M102(m, d, x, ...) m(d, 101, x) VL_ENUM_ID(VL_ENUM_M101(m, d, __VA_ARGS__))
#define VL_ENUM_M103(m, d, x, ...) m(d, 102, x) VL_ENUM_ID(VL_ENUM_M102(m, d, __VA_ARGS__))
#define VL_ENUM_M104(m, d, x, ...) m(d, 103, x) VL_ENUM_ID(VL_ENUM_M103(m, d, __VA_ARGS__))
#define VL_ENUM_M105(m, d, x, ...) m(d, 104, x) VL_ENUM_ID(VL_ENUM_M104(m, d, __VA_ARGS__))
#define VL_ENUM_M106(m, d, x, ...) m(d, 105, x) VL_ENUM_ID(VL_ENUM_M105(m, d, __VA_ARGS__))
#define VL_ENUM_M107(m, d, x, ...) m(d, 106, x) VL_ENUM_ID(VL_ENUM_M106(m, d, __VA_ARGS__))
#define VL_ENUM_M108(m, d, x, ...) m(d, 107, x) VL_ENUM_ID(VL_ENUM_M107(m, d, __VA_ARGS__))
#define VL_ENUM_M109(m, d, x, ...) m(d, 108, x) VL_ENUM_ID(VL_ENUM_M108(m, d, __VA_ARGS__))
#define VL_ENUM_M110(m, d, x, ...) m(d, 109, x) VL_ENUM_ID(VL_ENUM_M109(m, d, __VA_ARGS__))
#define VL_ENUM_M111(m, d, x, ...) m(d, 110, x) VL_ENUM_ID(VL_ENUM_M110(m, d, __VA_ARGS__))
#define VL_ENUM_M112(m, d, x, ...) m(d, 111, x) VL_ENUM_ID(VL_ENUM_M111(m, d, __VA_ARGS__))
#define VL_ENUM_M113(m, d, x, ...) m(d, 112, x) VL_ENUM_ID(VL_ENUM_M112(m, d, __VA_ARGS__))
#define VL_ENUM_M114(m, d, x, ...) m(d, 113, x) VL_ENUM_ID(VL_ENUM_M113(m, d, __VA_ARGS__))
#define VL_ENUM_M115(m, d, x, ...) m(d, 114, x) VL_ENUM_ID(VL_ENUM_M114(m, d, __VA_ARGS__))
#define VL_ENUM_M116(m, d, x, ...) m(d, 115, x) VL_ENUM_ID(VL_ENUM_M115(m, d, __VA_ARGS__))
#define VL_ENUM_M117(m, d, x, ...) m(d, 116, x) VL_ENUM_ID(VL_ENUM_M116(m, d, __VA_ARGS__))
#define VL_ENUM_M118(m, d, x, ...) m(d, 117, x) VL_ENUM_ID(VL_ENUM_M117(m, d, __VA_ARGS__))
#define VL_ENUM_M119(m, d, x, ...) m(d, 118, x) VL_ENUM_ID(VL_ENUM_M118(m, d, __VA_ARGS__))
#define VL_ENUM_M120(m, d, x, ...) m(d, 119, x) VL_ENUM_ID(VL_ENUM_M119(m, d, __VA_ARGS__))
#define VL_ENUM_M121(m, d, x, ...) m(d, 120, x) VL_ENUM_ID(VL_ENUM_M120(m, d, __VA_ARGS__))
#define VL_ENUM_M122(m, d, x, ...) m(d, 121, x) VL_ENUM_ID(VL_ENUM_M121(m, d, __VA_ARGS__))
#define VL_ENUM_M123(m, d, x, ...) m(d, 122, x) VL_ENUM_ID(VL_ENUM_M122(m, d, __VA_ARGS__))
#define VL_ENUM_M124(m, d, x, ...) m(d, 123, x) VL_ENUM_ID(VL_ENUM_M123(m, d, __VA_ARGS__))
#define VL_ENUM_M125(m, d, x, ...) m(d, 124, x) VL_ENUM_ID(VL_ENUM_M124(m, d, __VA_ARGS__))
#define VL_ENUM_M126(m, d, x, ...) m(d, 125, x) VL_ENUM_ID(VL_ENUM_M125(m, d, __VA_ARGS__))
#define VL_ENUM_M127(m, d, x, ...) m(d, 126, x) VL_ENUM_ID(VL_ENUM_M126(m, d, __VA_ARGS__))
#define VL_ENUM_M128(m, d, x, ...) m(d, 127, x) VL_ENUM_ID(VL_ENUM_M127(m, d, __VA_ARGS__))


#define VL_ENUM_PP_COUNT_IMPL(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64,_65,_66,_67,_68,_69,_70,_71,_72,_73,_74,_75,_76,_77,_78,_79,_80,_81,_82,_83,_84,_85,_86,_87,_88,_89,_90,_91,_92,_93,_94,_95,_96,_97,_98,_99,_100,_101,_102,_103,_104,_105,_106,_107,_108,_109,_110,_111,_112,_113,_114,_115,_116,_117,_118,_119,_120,_121,_122,_123,_124,_125,_126,_127,_128,count, ...) count

#define VL_ENUM_PP_COUNT(...)                                                                                     \
    VL_ENUM_ID(VL_ENUM_PP_COUNT_IMPL(__VA_ARGS__, 128,127,126,125,124,123,122,121,120,119,118,117,116,115,114,113,112,111,110,109,108,107,106,105,104,103,102,101,100,99,98,97,96,95,94,93,92,91,90,89,88,87,86,85,84,83,82,81,80,79,78,77,76,75,74,73,72,71,70,69,68,67,66,65, 64, 63, 62, 61, 60, 59, 58, 57, 56, 55, 54, 53, 52, 51, 50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1))

template<typename T>
struct is_vl_enum: std::false_type {};

template<typename T>
concept IsVlEnum = is_vl_enum<T>::value;

template<typename T>
T fromString(const std::string& value){
    static_assert(is_vl_enum<T>::value, "Type is not an VL_ENUM");
    throw std::runtime_error("fromString not implemented for this type");
}

namespace Velyra::Detail {
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
    (EnumType)((Velyra::Detail::_eat_assign<EnumType>)EnumType::expression),
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
                std::string value_str = Velyra::Detail::getEnumValue(VL_ENUM_RAW_NAMES_ARRAY_NAME[idx]); \
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
