#include <gtest/gtest.h>
#include <VelyraUtils/Types/SymbolicTypes.hpp>

using namespace Velyra;
using namespace Velyra::Utils;

class TestSymbolicTypes: public ::testing::Test {

};

TEST_F(TestSymbolicTypes, GetTypeSize) {
    EXPECT_EQ(getTypeSize(VL_TYPE_NONE), 0);
    EXPECT_EQ(getTypeSize(VL_VOID), 0);
    EXPECT_EQ(getTypeSize(VL_UINT8), 1);
    EXPECT_EQ(getTypeSize(VL_INT8), 1);
    EXPECT_EQ(getTypeSize(VL_UINT16), 2);
    EXPECT_EQ(getTypeSize(VL_INT16), 2);
    EXPECT_EQ(getTypeSize(VL_UINT32), 4);
    EXPECT_EQ(getTypeSize(VL_INT32), 4);
    EXPECT_EQ(getTypeSize(VL_UINT64), 8);
    EXPECT_EQ(getTypeSize(VL_INT64), 8);
    EXPECT_EQ(getTypeSize(VL_FLOAT16), 2);
    EXPECT_EQ(getTypeSize(VL_FLOAT32), 4);
    EXPECT_EQ(getTypeSize(VL_FLOAT64), 8);
}

TEST_F(TestSymbolicTypes, GetTypeSizeScalar) {
    EXPECT_EQ(getTypeSize(VL_UINT8_1), 1);
    EXPECT_EQ(getTypeSize(VL_UINT8_2), 2);
    EXPECT_EQ(getTypeSize(VL_UINT8_3), 3);
    EXPECT_EQ(getTypeSize(VL_UINT8_4), 4);
    EXPECT_EQ(getTypeSize(VL_UINT8_3X3), 9);
    EXPECT_EQ(getTypeSize(VL_UINT8_4X4), 16);

    EXPECT_EQ(getTypeSize(VL_INT8_1), 1);
    EXPECT_EQ(getTypeSize(VL_INT8_2), 2);
    EXPECT_EQ(getTypeSize(VL_INT8_3), 3);
    EXPECT_EQ(getTypeSize(VL_INT8_4), 4);
    EXPECT_EQ(getTypeSize(VL_INT8_3X3), 9);
    EXPECT_EQ(getTypeSize(VL_INT8_4X4), 16);

    EXPECT_EQ(getTypeSize(VL_UINT16_1), 2);
    EXPECT_EQ(getTypeSize(VL_UINT16_2), 4);
    EXPECT_EQ(getTypeSize(VL_UINT16_3), 6);
    EXPECT_EQ(getTypeSize(VL_UINT16_4), 8);
    EXPECT_EQ(getTypeSize(VL_UINT16_3X3), 18);
    EXPECT_EQ(getTypeSize(VL_UINT16_4X4), 32);

    EXPECT_EQ(getTypeSize(VL_INT16_1), 2);
    EXPECT_EQ(getTypeSize(VL_INT16_2), 4);
    EXPECT_EQ(getTypeSize(VL_INT16_3), 6);
    EXPECT_EQ(getTypeSize(VL_INT16_4), 8);
    EXPECT_EQ(getTypeSize(VL_INT16_3X3), 18);
    EXPECT_EQ(getTypeSize(VL_INT16_4X4), 32);

    EXPECT_EQ(getTypeSize(VL_UINT32_1), 4);
    EXPECT_EQ(getTypeSize(VL_UINT32_2), 8);
    EXPECT_EQ(getTypeSize(VL_UINT32_3), 12);
    EXPECT_EQ(getTypeSize(VL_UINT32_4), 16);
    EXPECT_EQ(getTypeSize(VL_UINT32_3X3), 36);
    EXPECT_EQ(getTypeSize(VL_UINT32_4X4), 64);

    EXPECT_EQ(getTypeSize(VL_INT32_1), 4);
    EXPECT_EQ(getTypeSize(VL_INT32_2), 8);
    EXPECT_EQ(getTypeSize(VL_INT32_3), 12);
    EXPECT_EQ(getTypeSize(VL_INT32_4), 16);
    EXPECT_EQ(getTypeSize(VL_INT32_3X3), 36);
    EXPECT_EQ(getTypeSize(VL_INT32_4X4), 64);

    EXPECT_EQ(getTypeSize(VL_UINT64_1), 8);
    EXPECT_EQ(getTypeSize(VL_UINT64_2), 16);
    EXPECT_EQ(getTypeSize(VL_UINT64_3), 24);
    EXPECT_EQ(getTypeSize(VL_UINT64_4), 32);
    EXPECT_EQ(getTypeSize(VL_UINT64_3X3), 72);
    EXPECT_EQ(getTypeSize(VL_UINT64_4X4), 128);

    EXPECT_EQ(getTypeSize(VL_INT64_1), 8);
    EXPECT_EQ(getTypeSize(VL_INT64_2), 16);
    EXPECT_EQ(getTypeSize(VL_INT64_3), 24);
    EXPECT_EQ(getTypeSize(VL_INT64_4), 32);
    EXPECT_EQ(getTypeSize(VL_INT64_3X3), 72);
    EXPECT_EQ(getTypeSize(VL_INT64_4X4), 128);

    EXPECT_EQ(getTypeSize(VL_FLOAT16_1), 2);
    EXPECT_EQ(getTypeSize(VL_FLOAT16_2), 4);
    EXPECT_EQ(getTypeSize(VL_FLOAT16_3), 6);
    EXPECT_EQ(getTypeSize(VL_FLOAT16_4), 8);
    EXPECT_EQ(getTypeSize(VL_FLOAT16_3X3), 18);
    EXPECT_EQ(getTypeSize(VL_FLOAT16_4X4), 32);

    EXPECT_EQ(getTypeSize(VL_FLOAT32_1), 4);
    EXPECT_EQ(getTypeSize(VL_FLOAT32_2), 8);
    EXPECT_EQ(getTypeSize(VL_FLOAT32_3), 12);
    EXPECT_EQ(getTypeSize(VL_FLOAT32_4), 16);
    EXPECT_EQ(getTypeSize(VL_FLOAT32_3X3), 36);
    EXPECT_EQ(getTypeSize(VL_FLOAT32_4X4), 64);

    EXPECT_EQ(getTypeSize(VL_FLOAT64_1), 8);
    EXPECT_EQ(getTypeSize(VL_FLOAT64_2), 16);
    EXPECT_EQ(getTypeSize(VL_FLOAT64_3), 24);
    EXPECT_EQ(getTypeSize(VL_FLOAT64_4), 32);
    EXPECT_EQ(getTypeSize(VL_FLOAT64_3X3), 72);
    EXPECT_EQ(getTypeSize(VL_FLOAT64_4X4), 128);
}

TEST_F(TestSymbolicTypes, GetComponentCount) {
    EXPECT_EQ(getComponentCount(VL_TYPE_NONE), 1);
    EXPECT_EQ(getComponentCount(VL_VOID), 1);
    EXPECT_EQ(getComponentCount(VL_UINT8), 1);
    EXPECT_EQ(getComponentCount(VL_INT8), 1);
    EXPECT_EQ(getComponentCount(VL_UINT16), 1);
    EXPECT_EQ(getComponentCount(VL_INT16), 1);
    EXPECT_EQ(getComponentCount(VL_UINT32), 1);
    EXPECT_EQ(getComponentCount(VL_INT32), 1);
    EXPECT_EQ(getComponentCount(VL_UINT64), 1);
    EXPECT_EQ(getComponentCount(VL_INT64), 1);
    EXPECT_EQ(getComponentCount(VL_FLOAT16), 1);
    EXPECT_EQ(getComponentCount(VL_FLOAT32), 1);
    EXPECT_EQ(getComponentCount(VL_FLOAT64), 1);
}

TEST_F(TestSymbolicTypes, GetComponentCountScalar) {
    EXPECT_EQ(getComponentCount(VL_UINT8_1), 1);
    EXPECT_EQ(getComponentCount(VL_UINT8_2), 2);
    EXPECT_EQ(getComponentCount(VL_UINT8_3), 3);
    EXPECT_EQ(getComponentCount(VL_UINT8_4), 4);
    EXPECT_EQ(getComponentCount(VL_UINT8_3X3), 9);
    EXPECT_EQ(getComponentCount(VL_UINT8_4X4), 16);

    EXPECT_EQ(getComponentCount(VL_INT8_1), 1);
    EXPECT_EQ(getComponentCount(VL_INT8_2), 2);
    EXPECT_EQ(getComponentCount(VL_INT8_3), 3);
    EXPECT_EQ(getComponentCount(VL_INT8_4), 4);
    EXPECT_EQ(getComponentCount(VL_INT8_3X3), 9);
    EXPECT_EQ(getComponentCount(VL_INT8_4X4), 16);

    EXPECT_EQ(getComponentCount(VL_UINT16_1), 1);
    EXPECT_EQ(getComponentCount(VL_UINT16_2), 2);
    EXPECT_EQ(getComponentCount(VL_UINT16_3), 3);
    EXPECT_EQ(getComponentCount(VL_UINT16_4), 4);
    EXPECT_EQ(getComponentCount(VL_UINT16_3X3), 9);
    EXPECT_EQ(getComponentCount(VL_UINT16_4X4), 16);

    EXPECT_EQ(getComponentCount(VL_INT16_1), 1);
    EXPECT_EQ(getComponentCount(VL_INT16_2), 2);
    EXPECT_EQ(getComponentCount(VL_INT16_3), 3);
    EXPECT_EQ(getComponentCount(VL_INT16_4), 4);
    EXPECT_EQ(getComponentCount(VL_INT16_3X3), 9);
    EXPECT_EQ(getComponentCount(VL_INT16_4X4), 16);

    EXPECT_EQ(getComponentCount(VL_UINT32_1), 1);
    EXPECT_EQ(getComponentCount(VL_UINT32_2), 2);
    EXPECT_EQ(getComponentCount(VL_UINT32_3), 3);
    EXPECT_EQ(getComponentCount(VL_UINT32_4), 4);
    EXPECT_EQ(getComponentCount(VL_UINT32_3X3), 9);
    EXPECT_EQ(getComponentCount(VL_UINT32_4X4), 16);

    EXPECT_EQ(getComponentCount(VL_INT32_1), 1);
    EXPECT_EQ(getComponentCount(VL_INT32_2), 2);
    EXPECT_EQ(getComponentCount(VL_INT32_3), 3);
    EXPECT_EQ(getComponentCount(VL_INT32_4), 4);
    EXPECT_EQ(getComponentCount(VL_INT32_3X3), 9);
    EXPECT_EQ(getComponentCount(VL_INT32_4X4), 16);

    EXPECT_EQ(getComponentCount(VL_UINT64_1), 1);
    EXPECT_EQ(getComponentCount(VL_UINT64_2), 2);
    EXPECT_EQ(getComponentCount(VL_UINT64_3), 3);
    EXPECT_EQ(getComponentCount(VL_UINT64_4), 4);
    EXPECT_EQ(getComponentCount(VL_UINT64_3X3), 9);
    EXPECT_EQ(getComponentCount(VL_UINT64_4X4), 16);

    EXPECT_EQ(getComponentCount(VL_INT64_1), 1);
    EXPECT_EQ(getComponentCount(VL_INT64_2), 2);
    EXPECT_EQ(getComponentCount(VL_INT64_3), 3);
    EXPECT_EQ(getComponentCount(VL_INT64_4), 4);
    EXPECT_EQ(getComponentCount(VL_INT64_3X3), 9);
    EXPECT_EQ(getComponentCount(VL_INT64_4X4), 16);

    EXPECT_EQ(getComponentCount(VL_FLOAT16_1), 1);
    EXPECT_EQ(getComponentCount(VL_FLOAT16_2), 2);
    EXPECT_EQ(getComponentCount(VL_FLOAT16_3), 3);
    EXPECT_EQ(getComponentCount(VL_FLOAT16_4), 4);
    EXPECT_EQ(getComponentCount(VL_FLOAT16_3X3), 9);
    EXPECT_EQ(getComponentCount(VL_FLOAT16_4X4), 16);

    EXPECT_EQ(getComponentCount(VL_FLOAT32_1), 1);
    EXPECT_EQ(getComponentCount(VL_FLOAT32_2), 2);
    EXPECT_EQ(getComponentCount(VL_FLOAT32_3), 3);
    EXPECT_EQ(getComponentCount(VL_FLOAT32_4), 4);
    EXPECT_EQ(getComponentCount(VL_FLOAT32_3X3), 9);
    EXPECT_EQ(getComponentCount(VL_FLOAT32_4X4), 16);

    EXPECT_EQ(getComponentCount(VL_FLOAT64_1), 1);
    EXPECT_EQ(getComponentCount(VL_FLOAT64_2), 2);
    EXPECT_EQ(getComponentCount(VL_FLOAT64_3), 3);
    EXPECT_EQ(getComponentCount(VL_FLOAT64_4), 4);
    EXPECT_EQ(getComponentCount(VL_FLOAT64_3X3), 9);
    EXPECT_EQ(getComponentCount(VL_FLOAT64_4X4), 16);
}
