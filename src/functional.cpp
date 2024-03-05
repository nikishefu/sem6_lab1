#include "numeric/functional.hpp"
#include "numeric/quadrature.hpp"
#include "numeric/derivative.hpp"
#include "numeric/polynomials.hpp"


double dotProduct(std::function<double(double)> f1, std::function<double(double)> f2) {
    return trapezoidal([f1, f2](double x){return f1(x) * f2(x);}, -1, 1, 1000);
}

double L(std::function<double(double)> p, std::function<double(double)> r,
         const unsigned int n, const unsigned int k, double x)
{
    return -p(x) * dOmega(n, k, 2)(x) - numDerivative(p, x) * dOmega(n, k, 1)(x) + r(x) * omega(n, k)(x);
}