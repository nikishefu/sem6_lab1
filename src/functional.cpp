#include "numeric/functional.hpp"
#include "numeric/quadrature.hpp"


double dotProduct(std::function<double(double)> f1, std::function<double(double)> f2) {
    return trapezoidal([f1, f2](double x){return f1(x) * f2(x);}, -1, 1, 1000);
}