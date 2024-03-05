#include <gtest/gtest.h>
#include "numeric/polynomials.hpp"
#include "numeric/derivative.hpp"


TEST(polynomials, JacobiBaseCases) {
    auto func = jacobi(0, 1);
    EXPECT_EQ(func(12), 1);

    func = jacobi(1, 1);
    EXPECT_EQ(func(12), 24);
}

TEST(polynomials, JacobiHigher_n) {
    auto func = jacobi(2, 1);
    EXPECT_EQ(func(-10), 374.25);

    func = jacobi(3, 1);
    EXPECT_EQ(func(-1), -4);

    func = jacobi(3, 1);
    EXPECT_EQ(func(6), 1494.0);

    func = jacobi(4, 1);
    EXPECT_EQ(func(8), 53200.625);
    
    func = jacobi(5, 1);
    EXPECT_EQ(func(-10), -2452537.5);

    func = jacobi(6, 1);
    EXPECT_EQ(func(8), 12079472.453125);
    
    func = jacobi(7, 1);
    EXPECT_EQ(func(6), 24056676.75);
}

TEST(polynomials, JacobiZero_k) {
    auto func = jacobi(4, 0);
    EXPECT_EQ(func(4), 1060.375);

    func = jacobi(5, 0);
    EXPECT_EQ(func(4), 7511.5);
}

TEST(polynomials, JacobiTwo_k) {
    auto func = jacobi(4, 2);
    EXPECT_EQ(func(4), 7650.9375);
}

TEST(polynomials, omega) {
    auto func = omega(4, 1);
    EXPECT_EQ(func(4), -48309.375);
}

TEST(polynomials, dOmega) {
    auto func = dOmega(4, 1, 1);
    EXPECT_EQ(func(4), -75115.0);
}

TEST(polynomials, dOmega2ndOrder) {
    auto func = dOmega(2, 2, 2);
    EXPECT_EQ(func(2), 2658.0);
}

TEST(polynomials, dOmegaAndNumDer) {
    auto func = omega(4, 1);
    auto dFunc = dOmega(4, 1, 1);
    EXPECT_NEAR(numDerivative(func, 0.2), dFunc(0.2), 1e-5);
}

TEST(polynomials, dOmegaAndNumDer2ndOrder) {
    auto func = dOmega(4, 1, 1);
    auto dFunc = dOmega(4, 1, 2);
    EXPECT_NEAR(numDerivative(func, 0.2), dFunc(0.2), 1e-5);
}