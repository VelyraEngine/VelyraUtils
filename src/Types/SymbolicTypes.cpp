#include <VelyraUtils/Types/SymbolicTypes.hpp>
#include <VelyraUtils/Logging.hpp>

namespace Velyra::Utils {

    constexpr auto CONVERTER_LOGGER_NAME = "UTI-CVT";

    U32 getTypeSize(const VL_TYPE type) {
        switch (type) {
            case VL_TYPE_NONE:
            case VL_VOID:       return 0;
            case VL_UINT8:
            case VL_INT8:       return 1;
            case VL_UINT16:
            case VL_INT16:      return 2;
            case VL_UINT32:
            case VL_INT32:      return 4;
            case VL_UINT64:
            case VL_INT64:      return 8;
            case VL_FLOAT16:    return 2;
            case VL_FLOAT32:    return 4;
            case VL_FLOAT64:    return 8;
            default: {
                const LogPtr logger = getLogger(CONVERTER_LOGGER_NAME);
                SPDLOG_LOGGER_WARN(logger, "Unknown type {}, returning typesize = 0", type);
                return 0;
            }
        }
    }


}
