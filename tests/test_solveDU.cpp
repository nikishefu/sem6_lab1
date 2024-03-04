#include <gtest/gtest.h>
#include <cmath>
#include "numeric/solveDU.hpp"

TEST(Ritz, test1) {
    auto p = [](double x){return 1 / (2 + x);};
    auto r = [](double x){return std::cos(x);};
    auto f = [](double x){return 1 + x;};
    std::cout << solveRitz(p, r, f, 5)(3) << std::endl;
}