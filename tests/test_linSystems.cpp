#include <gtest/gtest.h>
#include "numeric/linSystems.hpp"
#include <cmath>

TEST(linSystems, test3x3) {
    // 2x + y - z = 8
    // -3x - y + 2z = -11
    // -2x + y + 2z = -3

    std::vector<std::vector<double>> coefficients = {{2, 1, -1}, {-3, -1, 2}, {-2, 1, 2}};
    std::vector<double> constants = {8, -11, -3};

    std::vector<double> solution = gaussianElimination(coefficients, constants);

    std::vector<double> ans = {2, 3, -1};
    EXPECT_EQ(solution, ans);
}

TEST(linSystems, test5x5) {
    // 2x + y - z = 8
    // -3x - y + 2z = -11
    // -2x + y + 2z = -3

    std::vector<std::vector<double>> coefficients = {{2, 1, -1, 3, -10}, {-3, -1, 2, 1, 1}, {-2, 1, 2, -3, 12}, {3, -1, -3, 2, -1}, {0, 0, 1, 3, 1}};
    std::vector<double> constants = {8, -11, -3, 3, 50};

    std::vector<double> solution = gaussianElimination(coefficients, constants);
    for (double& value : solution) {value = std::round(value * 1e10) / 1e10;}

    std::vector<double> ans = {47.2372093023, -24.6697674419, 53.4465116279, -1.2976744186, 0.4465116279};
    EXPECT_EQ(solution, ans);
}