#include <vector>
#include "numeric/solveDU.hpp"
#include "numeric/functional.hpp"
#include "numeric/polynomials.hpp"
#include "numeric/linSystems.hpp"


std::function<double(double)> solveRitz(std::function<double(double)> p,
                                        std::function<double(double)> r,
                                        std::function<double(double)> f,
                                        unsigned int n)
{
    std::vector<std::vector<double>> A(n, std::vector<double>(n, 0));
    for (unsigned int i = 0; i < A.size(); ++i) {
        for (unsigned int j = 0; j < A[0].size(); ++j) {
            A[i][j] = bilinearForm(i, 1, j, 1, p, r);
        }
    }

    std::vector<double> B(n, 0);
    for (unsigned int i = 0; i < B.size(); ++i) {
        B[i] = dotProduct(f, omega(i, 1));
    }

    std::vector<double> coeffs = gaussianElimination(A, B);
    return [coeffs](double x){
        double res = 0;
        for (unsigned int i = 0; i < coeffs.size(); ++i) {
            res += coeffs[i] * omega(i, 1)(x);
        }
        return res;
    };
}
