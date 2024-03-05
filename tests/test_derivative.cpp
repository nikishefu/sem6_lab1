#include <gtest/gtest.h>
#include <cmath>
#include "numeric/derivative.hpp"


TEST(derivative, numDerivative) {
    auto func = [](double x){return x * x;};
    auto dFunc = [](double x){return 2 * x;};
    EXPECT_NEAR(numDerivative(func, 2), dFunc(2), 1e-10);
}

TEST(derivative, numDerivativeSinCos) {
    auto func = [](double x){return std::sin(x);};
    auto dFunc = [](double x){return std::cos(x);};
    EXPECT_NEAR(numDerivative(func, 2), dFunc(2), 1e-10);
}
