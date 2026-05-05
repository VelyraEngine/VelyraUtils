#include <VelyraUtils/DevUtils/PrettyTypeFormatter.hpp>
#include <VelyraUtils/DevUtils/Conditions.hpp>

#if defined(VL_COMPILER_GCC) || defined(VL_COMPILER_CLANG)

#include <cxxabi.h>
#include <memory>

namespace Velyra::Utils {

std::string prettyTypeName(const std::type_info& ti) {
    int status = 0;
    char *demangled = abi::__cxa_demangle(ti.name(), nullptr, nullptr, &status);
    const std::unique_ptr<char, void (*)(void *)> guard(demangled, std::free);
    return status == 0 ? guard.get() : ti.name();
}

}

#elif defined(VL_COMPILER_MSVC)

std::string prettyTypeName(const std::type_info& ti) {
    VL_NOT_IMPLEMENTED()
}

#endif

