#pragma once
#include <vector>

/* Function to perform Gaussian Elimination on a system of linear equations */
std::vector<double> gaussianElimination(const std::vector<std::vector<double>>& A, const std::vector<double>& B);