#include <iostream>
#include <climits>
#include <cstdlib>
#include <ctime>

// Рекурсивне заповнення матриці
void fillMatrixRecursively(int* matrix, int k, int n, int row, int col, int minVal, int maxVal) {
    if (row == k) return;
    if (col == n) {
        fillMatrixRecursively(matrix, k, n, row + 1, 0, minVal, maxVal);
        return;
    }
    *(matrix + row * n + col) = minVal + rand() % (maxVal - minVal + 1);
    fillMatrixRecursively(matrix, k, n, row, col + 1, minVal, maxVal);
}

// Рекурсивне виведення матриці
void printMatrixRecursively(const int* matrix, int k, int n, int row, int col) {
    if (row == k) return;
    if (col == n) {
        std::cout << std::endl;
        printMatrixRecursively(matrix, k, n, row + 1, 0);
        return;
    }
    std::cout << *(matrix + row * n + col) << "\t";
    printMatrixRecursively(matrix, k, n, row, col + 1);
}

// Рекурсивний пошук максимального елемента в рядку
int findMaxInRow(const int* matrix, int n, int row, int col, int maxInRow) {
    if (col == n) return maxInRow;
    if (*(matrix + row * n + col) > maxInRow) maxInRow = *(matrix + row * n + col);
    return findMaxInRow(matrix, n, row, col + 1, maxInRow);
}

// Рекурсивний пошук найменшого серед максимальних елементів у парних рядках
int findMinOfMaxInEvenRows(const int* matrix, int k, int n, int row, int minOfMax) {
    if (row >= k) return minOfMax;
    int maxInRow = findMaxInRow(matrix, n, row, 0, *(matrix + row * n));
    if (maxInRow < minOfMax) minOfMax = maxInRow;
    return findMinOfMaxInEvenRows(matrix, k, n, row + 2, minOfMax);
}

int main() {
    srand(time(0));
    const int K = 4;
    const int N = 5;
    int matrix[K][N];

    fillMatrixRecursively(&matrix[0][0], K, N, 0, 0, -10, 50);
    std::cout << "Матриця:\n";
    printMatrixRecursively(&matrix[0][0], K, N, 0, 0);

    int result = findMinOfMaxInEvenRows(&matrix[0][0], K, N, 0, INT_MAX);
    std::cout << "\nНайменший серед максимальних елементів у парних рядках: " << result << std::endl;

    return 0;
}