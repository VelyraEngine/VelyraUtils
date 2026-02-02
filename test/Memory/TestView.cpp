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
    UP<VibeData> data = createUP<VibeData>();
    const auto view = createView<VibeData>(data);
    const auto view2 = View<VibeData>(view);

    EXPECT_EQ(view2.get(), data.get());
}