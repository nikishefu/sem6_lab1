#pragma once

#include <functional>

/* Dot product in L2 space */
double dotProduct(std::function<double(double)> f1, std::function<double(double)> f2);


/* Ly = -(p(x)y')' + r(x)y, where y is omega(n, k)*/
double L(std::function<double(double)> p, std::function<double(double)> r,
         const unsigned int n, const unsigned int k, double x);