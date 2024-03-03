#pragma once

#include <functional>

std::function<double(double)> operator+(std::function<double(double)> f1,
                                        std::function<double(double)> f2)
{
  return [f1, f2](double x) -> double {return f1(x) + f2(x);};
}

std::function<double(double)> operator*(double num, std::function<double(double)> f) {
  return [num, f](double x) -> double {return num * f(x);};
}