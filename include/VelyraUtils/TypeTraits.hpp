#pragma once

#include <type_traits>

namespace Velyra::Utils {

    template<typename T>
    struct always_false : std::false_type {};

    template<typename T>
    constexpr bool always_false_v = always_false<T>::value;


}