#pragma once

#include <functional>

/* Dot product in L2 space */
double dotProduct(std::function<double(double)> f1, std::function<double(double)> f2);

double L(std::function<double(double)> y, std::function<double(double)> p, std::function<double(double)> r, double x);