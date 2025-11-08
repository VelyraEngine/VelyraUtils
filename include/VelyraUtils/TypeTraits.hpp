#pragma once

#include <type_traits>

namespace Velyra::Utils {

    template<typename T>
    struct always_false: std::false_type {};

}