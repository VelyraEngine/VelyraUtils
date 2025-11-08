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

namespace Velyra::Utils {

    /**
     * @brief Returns the size of a VL_TYPE in bytes. We expect the same type size as on an X86_64 reference platform
     * @param type
     * @return Type size in bytes
     */
    U32 VL_API getTypeSize(VL_TYPE type);



}