#include <gtest/gtest.h>
#include <VelyraUtils/Types/KeyVector.hpp>

using namespace Velyra;
using namespace Velyra::Utils;

class TestKeyVector: public ::testing::Test {

};

TEST_F(TestKeyVector, BasicOperations) {
    KeyVector<int, int> vec;
    vec.insert(0, 10);
    vec.insert(1, 20);
    vec.insert(2, 30);
    vec.insert(3, 40);

    EXPECT_EQ(vec.getSize(), 4);
    EXPECT_TRUE(vec.has(0));
    EXPECT_TRUE(vec.has(1));
    EXPECT_TRUE(vec.has(2));
    EXPECT_TRUE(vec.has(3));

    vec.remove(2);
    EXPECT_EQ(vec.getSize(), 3);
    EXPECT_FALSE(vec.has(2));
    EXPECT_TRUE(vec.has(0));
    EXPECT_TRUE(vec.has(1));
    EXPECT_TRUE(vec.has(3));

    vec.remove(0);
    EXPECT_EQ(vec.getSize(), 2);
    EXPECT_FALSE(vec.has(0));
    EXPECT_TRUE(vec.has(1));

    std::vector<int> data;
    for (const auto& item: vec) {
        data.push_back(item);
    }
    EXPECT_EQ(data.size(), 2);
}

struct Position {
    float x;
    float y;

    Position(float x_, float y_) : x(x_), y(y_) {}
};

TEST_F(TestKeyVector, EmplaceAndRetrieve) {
    KeyVector<int, Position> vec;
    vec.emplace(0, 2.0f, 3.0f);
    vec.emplace(1, 4.0f, 5.0f);
    vec.emplace(2, 6.0f, 7.0f);

    EXPECT_EQ(vec[0].x, 2.0f);
    EXPECT_EQ(vec[0].y, 3.0f);
    EXPECT_EQ(vec.get(1).x, 4.0f);
    EXPECT_EQ(vec.get(1).y, 5.0f);
    EXPECT_EQ(vec[2].x, 6.0f);
    EXPECT_EQ(vec[2].y, 7.0f);
}

TEST_F(TestKeyVector, InsertRemoveSingleElement) {
    KeyVector<int, Position> vec;
    vec.emplace(0, 2.0f, 3.0f);

    EXPECT_EQ(vec[0].x, 2.0f);
    EXPECT_EQ(vec[0].y, 3.0f);

    vec.remove(0);

    EXPECT_FALSE(vec.has(0));
}

TEST_F(TestKeyVector, InsertRemoveSameOrder) {
    KeyVector<int, Position> vec;
    vec.emplace(0, 2.0f, 3.0f);
    vec.emplace(1, 2.0f, 3.0f);
    vec.emplace(2, 2.0f, 3.0f);

    EXPECT_TRUE(vec.has(0));
    EXPECT_TRUE(vec.has(1));
    EXPECT_TRUE(vec.has(2));

    vec.remove(0);
    EXPECT_FALSE(vec.has(0));
    EXPECT_TRUE(vec.has(1));
    EXPECT_TRUE(vec.has(2));

    vec.remove(1);
    EXPECT_FALSE(vec.has(0));
    EXPECT_FALSE(vec.has(1));
    EXPECT_TRUE(vec.has(2));

    vec.remove(2);
    EXPECT_FALSE(vec.has(0));
    EXPECT_FALSE(vec.has(1));
    EXPECT_FALSE(vec.has(2));
}

TEST_F(TestKeyVector, InsertRemoveReverseOrder) {
    KeyVector<int, Position> vec;
    vec.emplace(0, 2.0f, 3.0f);
    vec.emplace(1, 2.0f, 3.0f);
    vec.emplace(2, 2.0f, 3.0f);

    EXPECT_TRUE(vec.has(0));
    EXPECT_TRUE(vec.has(1));
    EXPECT_TRUE(vec.has(2));

    vec.remove(2);
    EXPECT_TRUE(vec.has(0));
    EXPECT_TRUE(vec.has(1));
    EXPECT_FALSE(vec.has(2));

    vec.remove(1);
    EXPECT_TRUE(vec.has(0));
    EXPECT_FALSE(vec.has(1));
    EXPECT_FALSE(vec.has(2));

    vec.remove(0);
    EXPECT_FALSE(vec.has(0));
    EXPECT_FALSE(vec.has(1));
    EXPECT_FALSE(vec.has(2));
}
