import numpy as np
from scipy.linalg import solve

# Example system of equations:
#  2x + y - z = 8
# -3x - y + 2z = -11
# -2x + y + 2z = -3

A = np.array([[2, 1, -1], [-3, -1, 2], [-2, 1, 2]])
B = np.array([8, -11, -3])

# Solve the system using Scipy
solution = solve(A, B)

print("Solution:")
for i, x in enumerate(solution):
    print(f"x{i + 1} = {round(x, 6)}")


A = np.array([[2, 1, -1, 3, -10], [-3, -1, 2, 1, 1], [-2, 1, 2, -3, 12], [3, -1, -3, 2, -1], [0, 0, 1, 3, 1]])
B = np.array([8, -11, -3, 3, 50])

# Solve the system using Scipy
solution = solve(A, B)

print("Solution:")
for i, x in enumerate(solution):
    print(round(x, 10))
