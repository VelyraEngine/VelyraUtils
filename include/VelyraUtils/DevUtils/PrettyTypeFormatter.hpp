#pragma once

#include <string>
#include <typeinfo>

namespace Velyra::Utils {

std::string prettyTypeName(const std::type_info &ti);

template<typename T>
std::string prettyTypeName() {
    return prettyTypeName(typeid(T));
}

}