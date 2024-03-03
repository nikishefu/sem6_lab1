#include <gtest/gtest.h>
#include "numeric/funcOps.hpp"


TEST(funcOpsTest, Sum) {
    auto f1 = [](double x) -> double {return x*x;};
    auto f2 = [](double x) -> double {return 2*x;};

    auto expectedRes = [](double x) -> double {return x*x + 2*x;};
    auto result = f1 + f2;

    for (double argument = -10; argument < 10; argument += 0.14) {
        EXPECT_EQ(result(argument), expectedRes(argument));
    }
}

TEST(funcOpsTest, Scale) {
    auto f1 = [](double x) -> double {return x*x;};
    double scale = 0.217892;

    auto expectedRes = [scale](double x) -> double {return scale*(x*x);};
    auto result = scale * f1;

    for (double argument = -10; argument < 10; argument += 0.14) {
        EXPECT_EQ(result(argument), expectedRes(argument)) << "Argument = " << argument << ", Diff = " << result(argument) - expectedRes(argument);
    }
}