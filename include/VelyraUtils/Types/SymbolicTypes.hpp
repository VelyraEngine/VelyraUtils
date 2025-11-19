#pragma once

#include <VelyraUtils/ExportUtils.hpp>
#include <VelyraUtils/VelyraEnum.hpp>
#include <VelyraUtils/Types/Types.hpp>

VL_ENUM(VL_TYPE, U8,
    VL_TYPE_NONE    = 0x00,
    VL_VOID         = 0x10,
    VL_UINT8        = 0x20,
    VL_INT8         = 0x30,
    VL_UINT16       = 0x40,
    VL_INT16        = 0x50,
    VL_UINT32       = 0x60,
    VL_INT32        = 0x70,
    VL_UINT64       = 0x80,
    VL_INT64        = 0x90,
    VL_FLOAT16      = 0xA0,
    VL_FLOAT32      = 0xB0,
    VL_FLOAT64      = 0xC0
);

/**
 * @brief 4D linear Algebra types. The upper 4 bits indicate the underlying VL_TYPE, the lower 4 bits the number
 *           of elements. Note that 0000 represents 1 element and 1111 (FF) represents 16
 */
VL_ENUM(VL_SCALAR_TYPE, U8,
    VL_UINT8_1      = 0x20,
    VL_UINT8_2      = 0x21,
    VL_UINT8_3      = 0x22,
    VL_UINT8_4      = 0x23,
    VL_UINT8_3X3    = 0x28,
    VL_UINT8_4X4    = 0x2F,

    VL_INT8_1       = 0x30,
    VL_INT8_2       = 0x31,
    VL_INT8_3       = 0x32,
    VL_INT8_4       = 0x33,
    VL_INT8_3X3     = 0x38,
    VL_INT8_4X4     = 0x3F,

    VL_UINT16_1     = 0x40,
    VL_UINT16_2     = 0x41,
    VL_UINT16_3     = 0x42,
    VL_UINT16_4     = 0x43,
    VL_UINT16_3X3   = 0x48,
    VL_UINT16_4X4   = 0x4F,

    VL_INT16_1      = 0x50,
    VL_INT16_2      = 0x51,
    VL_INT16_3      = 0x52,
    VL_INT16_4      = 0x53,
    VL_INT16_3X3    = 0x58,
    VL_INT16_4X4    = 0x5F,

    VL_UINT32_1     = 0x60,
    VL_UINT32_2     = 0x61,
    VL_UINT32_3     = 0x62,
    VL_UINT32_4     = 0x63,
    VL_UINT32_3X3   = 0x68,
    VL_UINT32_4X4   = 0x6F,

    VL_INT32_1      = 0x70,
    VL_INT32_2      = 0x71,
    VL_INT32_3      = 0x72,
    VL_INT32_4      = 0x73,
    VL_INT32_3X3    = 0x78,
    VL_INT32_4X4    = 0x7F,

    VL_UINT64_1     = 0x80,
    VL_UINT64_2     = 0x81,
    VL_UINT64_3     = 0x82,
    VL_UINT64_4     = 0x83,
    VL_UINT64_3X3   = 0x88,
    VL_UINT64_4X4   = 0x8F,

    VL_INT64_1      = 0x90,
    VL_INT64_2      = 0x91,
    VL_INT64_3      = 0x92,
    VL_INT64_4      = 0x93,
    VL_INT64_3X3    = 0x98,
    VL_INT64_4X4    = 0x9F,

    VL_FLOAT16_1    = 0xA0,
    VL_FLOAT16_2    = 0xA1,
    VL_FLOAT16_3    = 0xA2,
    VL_FLOAT16_4    = 0xA3,
    VL_FLOAT16_3X3  = 0xA8,
    VL_FLOAT16_4X4  = 0xAF,

    VL_FLOAT32_1    = 0xB0,
    VL_FLOAT32_2    = 0xB1,
    VL_FLOAT32_3    = 0xB2,
    VL_FLOAT32_4    = 0xB3,
    VL_FLOAT32_3X3  = 0xB8,
    VL_FLOAT32_4X4  = 0xBF,

    VL_FLOAT64_1    = 0xC0,
    VL_FLOAT64_2    = 0xC1,
    VL_FLOAT64_3    = 0xC2,
    VL_FLOAT64_4    = 0xC3,
    VL_FLOAT64_3X3  = 0xC8,
    VL_FLOAT64_4X4  = 0xCF
);

namespace Velyra::Utils {

    /**
     * @brief Returns the size of a VL_TYPE in bytes. We expect the same type size as on an X86_64 reference platform
     * @param type
     * @return Type size in bytes
     */
    U32 VL_API getTypeSize(VL_TYPE type);
    U32 VL_API getTypeSize(VL_SCALAR_TYPE type);

    /**
     * @brief Returns the number of components in a VL_TYPE or VL_SCALAR_TYPE. For normal types this is always 1.
     * @param type VL_TYPE or VL_SCALAR_TYPE
     * @return Number of components
     */
    U32 VL_API getComponentCount(VL_TYPE type);
    U32 VL_API getComponentCount(VL_SCALAR_TYPE type);



}