#include <iostream>
#include <eigen3/Eigen/Dense>
#include <boost/math/quadrature/trapezoidal.hpp>

using boost::math::quadrature::trapezoidal;
int main () {
  auto f = [](double x) { return sin(x); };
  double I = trapezoidal(f, 0.0, boost::math::constants::pi<double>());
  std::cout << "Integral: " << I << std::endl;
  return 0;
}
