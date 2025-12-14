#pragma once

#include <cstdint>
#include <cstddef>
#include <memory>

using U8 = uint8_t;
using I8 = int8_t;
using U16 = uint16_t;
using I16 = int16_t;
using U32 = uint32_t;
using I32 = int32_t;
using U64 = uint64_t;
using I64 = int64_t;

using UByte = unsigned char;
using SByte = char;

using Size = std::size_t;
using Index = std::size_t;
using UID = U64;

namespace Velyra {

    template<typename T>
    using UP = std::unique_ptr<T>;

    template<typename T>
    using SP = std::shared_ptr<T>;

    template<typename T, typename... Args>
    UP<T> createUP(Args&&... args){
        return std::make_unique<T>(std::forward<Args>(args)...);
    }

    template<typename T, typename... Args>
    SP<T> createSP(Args&&... args){
        return std::make_shared<T>(std::forward<Args>(args)...);
    }

}