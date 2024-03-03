#include <gtest/gtest.h>
#include "numeric/polynomials.hpp"


TEST(polynomials, JacobiBaseCases) {
    auto func = jacobi(0);
    EXPECT_EQ(func(12), 1);

    func = jacobi(1);
    EXPECT_EQ(func(12), 24);
}

TEST(polynomials, JacobiHigher_n) {
    auto func = jacobi(2);
    EXPECT_EQ(func(-10), 374.25);

    func = jacobi(3);
    EXPECT_EQ(func(-1), -4);

    func = jacobi(3);
    EXPECT_EQ(func(6), 1494.0);

    func = jacobi(4);
    EXPECT_EQ(func(8), 53200.625);
    
    func = jacobi(5);
    EXPECT_EQ(func(-10), -2452537.5);

    func = jacobi(6);
    EXPECT_EQ(func(8), 12079472.453125);
    
    func = jacobi(7);
    EXPECT_EQ(func(6), 24056676.75);
}