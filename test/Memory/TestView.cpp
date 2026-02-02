#include <gtest/gtest.h>

#include <VelyraUtils/Memory/View.hpp>

using namespace Velyra;

class TestView : public ::testing::Test {};

struct VibeData {
    double position = 0.0;
    double velocity = 0.0;

    double calculateSomething(const double t) const {
        return t * velocity + position;
    }
};

TEST_F(TestView, CreateView) {
    const UP<VibeData> data = createUP<VibeData>();
    const auto view = createView<VibeData>(data);

    EXPECT_EQ(view.get(), data.get());
}

TEST_F(TestView, CopyView) {
    const UP<VibeData> data = createUP<VibeData>();
    const auto view = createView<VibeData>(data);

    const View<VibeData> view2(view);
    EXPECT_EQ(view2.get(), data.get());

    const View<VibeData> view3 = view;
    EXPECT_EQ(view3.get(), data.get());
}

TEST_F(TestView, Nullptr) {
    View<VibeData> view = nullptr;

    EXPECT_TRUE(view == nullptr);

    const UP<VibeData> data = createUP<VibeData>();
    view = createView<VibeData>(data);
    EXPECT_TRUE(view != nullptr);

    view = nullptr;
    EXPECT_TRUE(view == nullptr);

    view = data;
    EXPECT_TRUE(view != nullptr);
}

TEST_F(TestView, MemberAccess) {
    UP<VibeData> data = createUP<VibeData>();
    const auto view = createView<VibeData>(data);
    view->position = 2.0;
    view->velocity = 2.0;
    EXPECT_DOUBLE_EQ(view->calculateSomething(2.0), 6.0);
}