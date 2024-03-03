# Print a table of Jacobi polinomials values using scipy to test my own implementation

from scipy.special import eval_jacobi

for n in range(2, 8):
    for x in range(-10, 10):
        print(n, x, end=" ")
        print(eval_jacobi(n,1,1,x))
