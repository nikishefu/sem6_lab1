#pragma once

double numDerivative(std::function<double(double)> func, double x) {
    double delta = 1e-5;
    return (func(x + delta) - func(x - delta)) / (2 * delta);
}