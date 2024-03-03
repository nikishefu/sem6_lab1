#include <numeric/polynomials.hpp>
#include <unordered_map>

std::function<double(double)> jacobi(unsigned int n) {
    // Base cases
    if (n == 0) {return ([](double x) -> double {return 1;});}
    if (n == 1) {return ([](double x) -> double {return 2*x;});}

    // Search in a cache
    static std::unordered_map<unsigned int, std::function<double(double)>> cache;
    auto funcP = cache.find(n);
    if (funcP != cache.end()) {return funcP->second;}

    // Compute if n >= 2 and didn't find in cache
    auto f1 = jacobi(0);
    auto f2 = jacobi(1);
    std::function<double(double)> f3;

    unsigned int c1, c2, c3;
    for (unsigned int i = 0; i <= n - 2; ++i) {
        c1 = (i + 3) * (2*i + 5);
        c2 = (i + 3) * (i + 2);
        c3 = (i + 4) * (i + 2);
        f3 = [c1,c2,c3, f1,f2](double x) -> double {return (c1 * x * f2(x) - c2 * f1(x))/c3;};
        f1 = f2;
        f2 = f3;
    }

    cache[n] = f3;
    return f3;
}