#include "numeric/linSystems.hpp"


std::vector<double> gaussianElimination(const std::vector<std::vector<double>>& A, const std::vector<double>& B) {
    int n = A.size(); // Number of equations
    int m = A[0].size(); // Number of variables

    // Augment the matrix A with the vector B to form an augmented matrix [A | B]
    std::vector<std::vector<double>> augmentedMatrix(n, std::vector<double>(m + 1));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            augmentedMatrix[i][j] = A[i][j];
        }
        augmentedMatrix[i][m] = B[i];
    }

    // Gaussian Elimination
    for (int i = 0; i < n; ++i) {
        // Make the diagonal element of the current row equal to 1
        double pivot = augmentedMatrix[i][i];
        for (int j = i; j <= m; ++j) {
            augmentedMatrix[i][j] /= pivot;
        }

        // Eliminate other rows
        for (int k = 0; k < n; ++k) {
            if (k != i) {
                double factor = augmentedMatrix[k][i];
                for (int j = i; j <= m; ++j) {
                    augmentedMatrix[k][j] -= factor * augmentedMatrix[i][j];
                }
            }
        }
    }

    // Extract the solution vector from the augmented matrix
    std::vector<double> solution(n);
    for (int i = 0; i < n; ++i) {
        solution[i] = augmentedMatrix[i][m];
    }

    return solution;
}