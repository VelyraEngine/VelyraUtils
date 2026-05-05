#include <gtest/gtest.h>
#include <VelyraUtils/DevUtils/CartesianProduct.hpp>

using namespace Velyra;
using namespace Velyra::Utils;

class TestCartesianProduct: public ::testing::Test {
};

TEST_F(TestCartesianProduct, CartesianProductOfTwoLists) {
    using List1 = TypeList<int, float>;
    using List2 = TypeList<char, double>;

    using Product = CartesianProduct<List1, List2>::type;

    // Expected product: (int, char), (float, char), (int, double), (float, double)
    using Expected = TypeList<std::tuple<int, char>, std::tuple<float, char>, std::tuple<int, double>,
                              std::tuple<float, double>>;

    EXPECT_TRUE((std::is_same_v<Product, Expected>));
}

using TA = TypeList<int, float>;
using TB = TypeList<char, double>;
using TC = TypeList<bool, long>;

using Cases = ToGTestTypes<CartesianProduct<TA, TB, TC>::type>::type;

template<typename WRAPPER>
class TestCartesianProductCase : public ::testing::Test
{
};

TYPED_TEST_SUITE(TestCartesianProductCase, Cases);

TYPED_TEST(TestCartesianProductCase, VerifyType)
{
    using CaseType = TypeParam;
    EXPECT_TRUE((std::is_same_v<CaseType, std::tuple<int, char, bool>> ||
                 std::is_same_v<CaseType, std::tuple<int, char, long>> ||
                 std::is_same_v<CaseType, std::tuple<int, double, bool>> ||
                 std::is_same_v<CaseType, std::tuple<int, double, long>> ||
                 std::is_same_v<CaseType, std::tuple<float, char, bool>> ||
                 std::is_same_v<CaseType, std::tuple<float, char, long>> ||
                 std::is_same_v<CaseType, std::tuple<float, double, bool>> ||
                 std::is_same_v<CaseType, std::tuple<float, double, long>>));
}

