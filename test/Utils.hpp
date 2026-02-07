#pragma once

#include <VelyraUtils/VelyraEnum.hpp>

VL_ENUM(COLOR, int,
    COLOR_UNKNOWN = 0,
    COLOR_RED = 1,
    COLOR_GREEN = 2,
    COLOR_BLUE = 4,
    COLOR_YELLOW = 8
);

VL_ENUM(SHAPE, int,
    SHAPE_UNKNOWN,
    SHAPE_CIRCLE,
    SHAPE_SQUARE,
    SHAPE_TRIANGLE
);