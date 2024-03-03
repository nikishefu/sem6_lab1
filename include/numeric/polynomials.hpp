#pragma once

#include <functional>
#include <vector>

/* returns a Jacobi polynomial P_n^(1,1)(x) */
std::function<double(double)> jacobi(unsigned int n);
std::vector<std::function<double(double)>> jacobiArray(unsigned int n);