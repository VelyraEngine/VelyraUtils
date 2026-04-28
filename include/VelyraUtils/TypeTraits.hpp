#pragma once

#include <type_traits>

#include <VelyraUtils/Types/SymbolicTypes.hpp>

namespace Velyra::Utils {

    template<typename T>
    struct always_false : std::false_type {};

    template<typename T>
    constexpr bool always_false_v = always_false<T>::value;

    template<VL_TYPE>
    struct VLTypeToCpp;

    template<>
    struct VLTypeToCpp<VL_UINT8> {
        using type = U8;
    };

    template<>
    struct VLTypeToCpp<VL_INT8> {
        using type = I8;
    };

    template<>
    struct VLTypeToCpp<VL_UINT16> {
        using type = U16;
    };

    template<>
    struct VLTypeToCpp<VL_INT16> {
        using type = I16;
    };

    template<>
    struct VLTypeToCpp<VL_UINT32> {
        using type = U32;
    };

    template<>
    struct VLTypeToCpp<VL_INT32> {
        using type = I32;
    };

    template<>
    struct VLTypeToCpp<VL_UINT64> {
        using type = U64;
    };

    template<>
    struct VLTypeToCpp<VL_INT64> {
        using type = I64;
    };

    // template<>
    // struct VLTypeToCpp<VL_FLOAT16> {
    //     static_assert(sizeof(float) == 4, "Expected float to be) 32 bits");
    // };

    template<>
    struct VLTypeToCpp<VL_FLOAT32> {
        using type = float;
    };

    template<>
    struct VLTypeToCpp<VL_FLOAT64> {
        using type = double;
    };
}