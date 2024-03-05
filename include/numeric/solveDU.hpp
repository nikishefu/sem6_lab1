#pragma once

#include <functional>

/* Solve DU -(p(x)y')' + r(x)y = f(x) using Ritz method */
std::function<double(double)> solveRitz(std::function<double(double)> p,
                                        std::function<double(double)> r,
                                        std::function<double(double)> f,
                                        unsigned int n);

/* Solve DU -(p(x)y')' + r(x)y = f(x) using collocation method */
std::function<double(double)> solveCollocation(std::function<double(double)> p,
                                               std::function<double(double)> r,
                                               std::function<double(double)> f,
                                               unsigned int n);