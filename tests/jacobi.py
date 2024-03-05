# Print a table of Jacobi polinomials values using scipy to test my own implementation

from scipy.special import eval_jacobi

for n in range(2, 8):
    for x in range(-10, 10):
        print(n, x, end=" ")
        print(eval_jacobi(n,1,1,x))

print(eval_jacobi(4, 0, 0, 4))
print(eval_jacobi(4, 2, 2, 4))
print(eval_jacobi(5, 0, 0, 4))

# Omega
print(-15 * eval_jacobi(4, 1, 1, 4))
# Omega derivative
print(-10 * eval_jacobi(5, 0, 0, 4))

# Omega 2nd derivative
print(4 * 3 * 4 * eval_jacobi(4, 0, 0, 2))
