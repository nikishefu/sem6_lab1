#pragma once

#include <functional>

double trapezoidal(std::function<double(double)> f, double a, double b, int n);