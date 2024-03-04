#include <gtest/gtest.h>
#include <cmath>
#include "numeric/functional.hpp"
#include "numeric/polynomials.hpp"

TEST(functional, dotProductSinCos) {
    EXPECT_NEAR(dotProduct([](double x){return std::sin(x);}, [](double x){return std::cos(x);}), 0, 1e-15);
}

TEST(functional, dotProductOmega) {
    EXPECT_NEAR(dotProduct(omega(2, 1), omega(3, 1)), 0, 1e-15);
}