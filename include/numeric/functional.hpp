#pragma once

#include <functional>

/* Dot product in L2 space */
double dotProduct(std::function<double(double)> f1, std::function<double(double)> f2);

/* Bilinear form, [y, z] = (Ly, z). README for more information. */
double biForm(std::function<double(double)> f1, std::function<double(double)> f2);