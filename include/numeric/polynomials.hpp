#pragma once

#include <functional>
#include <vector>

/* returns a Jacobi polynomial P_n^(k,k)(x) */
std::function<double(double)> jacobi(const unsigned int n, const unsigned int k);

/* returns one of orthogonal polynomials (1-x^2)^k * P_n^(k,k)(x) */
std::function<double(double)> omega(const unsigned int n, const unsigned int k);

/* returns a order-th derivative of omega(n, k) */
std::function<double(double)> dOmega(const unsigned int n, const unsigned int k, const unsigned int order);

/*
 *  [y, z] = (Ly, z), Ly = -(p(x)y')' + r(x)y
 *                           ^          ^
 *  The function is correct for a specific case (more info in README).
 *  Can only be applied to omega functions: [omega1(n1, k1), omega2(n2, k2)]
 *  The reason for taking n and k as an argument instead of std::function is that
 *  the form includes derivatives of input functions, therefore uses dOmega function.
 *  Numerical differentiation is much less resource-efficient than using dOmega function,
 *  considering that we only deal with omega functions.
 */
double bilinearForm(const unsigned int n1, const unsigned int k1,
                    const unsigned int n2, const unsigned int k2,
                    std::function<double(double)> p, std::function<double(double)> r);

std::vector<double> chebyshevRoots(const unsigned int n);
