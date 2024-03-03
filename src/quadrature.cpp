#include "numeric/quadrature.hpp"

double trapezoidal(std::function<double(double)> f, double a, double b, int n) {
  // Calculate the step size
  double h = (b - a) / n;

  // Initialize the result with the average of the function at the endpoints
  double result = 0.5 * (f(a) + f(b));

  // Perform the trapezoidal rule summation
  for (int i = 1; i < n; ++i) {
      double x = a + i * h;
      result += f(x);
  }

  // Multiply by the step size to get the final result
  result *= h;

  return result;
}