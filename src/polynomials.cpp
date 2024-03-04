#include <numeric/polynomials.hpp>
#include <unordered_map>
#include <cmath>
#include "numeric/quadrature.hpp"


// Hash function for a pair of unsigned ints
struct PairHash {
    template <typename T1, typename T2>
    std::size_t operator () (const std::pair<T1, T2>& p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);

        // Combine the hash values
        return h1 ^ h2;
    }
};

std::function<double(double)> jacobi(const unsigned int n, const unsigned int k) {
    // Base cases
    if (n == 0) {return ([](double x) -> double {return 1;});}
    if (n == 1) {return ([k](double x) -> double {return (k+1)*x;});}

    // Search in a cache
    static std::unordered_map<std::pair<unsigned int, unsigned int>, std::function<double(double)>, PairHash> cache;
    auto funcP = cache.find(std::make_pair(n, k));
    if (funcP != cache.end()) {return funcP->second;}

    // Compute if n >= 2 and didn't find in cache
    auto f1 = jacobi(0, k);
    auto f2 = jacobi(1, k);
    std::function<double(double)> f3;

    unsigned int c1, c2, c3;
    for (unsigned int i = 0; i <= n - 2; ++i) {
        c1 = (i + k + 2) * (2*i + 2*k + 3);
        c2 = (i + k + 2) * (i + k + 1);
        c3 = (i + 2*k + 2) * (i + 2);
        f3 = [c1,c2,c3, f1,f2](double x) -> double {return (c1 * x * f2(x) - c2 * f1(x))/c3;};
        f1 = f2;
        f2 = f3;
    }

    cache[std::make_pair(n, k)] = f3;
    return f3;
}


std::function<double(double)> omega(const unsigned int n, const unsigned int k) {
    return [n, k](double x){return std::pow((1-x*x), k) * jacobi(n, k)(x);};
}

std::function<double(double)> dOmega(const unsigned int n, const unsigned int k) {
    return [n, k](double x){return -2 * (int)(n+1) * std::pow((1-x*x), k-1) * jacobi(n+1, k-1)(x);};
}

double bilinearForm(const unsigned int n1, const unsigned int k1,
                    const unsigned int n2, const unsigned int k2,
                    std::function<double(double)> p, std::function<double(double)> r)
{
    auto dOm1 = dOmega(n1, k1);
    auto dOm2 = dOmega(n2, k2);
    auto om1 = omega(n1, k1);
    auto om2 = omega(n2, k2);
    return trapezoidal([p, r, dOm1, dOm2, om1, om2](double x){return p(x) * dOm1(x) * dOm2(x) +
                                               r(x) *  om1(x) *  om2(x);}, -1, 1, 1000);
}
