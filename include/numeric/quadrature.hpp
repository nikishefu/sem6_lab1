#pragma once

#include <functional>

/* Trapezoidal definite integral of f from a to b, n steps */
double trapezoidal(std::function<double(double)> f, double a, double b, int n);