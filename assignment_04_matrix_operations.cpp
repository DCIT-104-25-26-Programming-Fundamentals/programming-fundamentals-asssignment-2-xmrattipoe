#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void readMatrix(int matrix[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

void printMatrix(int matrix[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}

void transpose(int matrix[10][10], int rows, int cols, int result[10][10]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

void addMatrices(int a[10][10], int b[10][10], int rows, int cols, int result[10][10]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

void multiplyMatrices(int a[10][10], int b[10][10], int rowsA, int colsA, int colsB, int result[10][10]) {
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            int total = 0;
            for (int k = 0; k < colsA; k++) {
                total += a[i][k] * b[k][j];
            }
            result[i][j] = total;
        }
    }
}

int main() {
    int matrixA[10][10], result[10][10];
    int rows, cols;

    cout << "--- Part A: Transpose ---" << endl;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;
    readMatrix(matrixA, rows, cols);

    transpose(matrixA, rows, cols, result);
    cout << "Transposed Matrix:" << endl;
    printMatrix(result, cols, rows);

    cout << "\n--- Part B: Add Two Matrices ---" << endl;
    int m1[10][10], m2[10][10], sumResult[10][10];
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;
    cout << "First matrix:" << endl;
    readMatrix(m1, rows, cols);
    cout << "Second matrix:" << endl;
    readMatrix(m2, rows, cols);

    addMatrices(m1, m2, rows, cols, sumResult);
    cout << "Sum Matrix:" << endl;
    printMatrix(sumResult, rows, cols);

    cout << "\n--- Part C: Multiply Two Matrices ---" << endl;
    int ma[10][10], mb[10][10], productResult[10][10];
    int rowsA, colsA, colsB;
    cout << "Enter rows for matrix A: ";
    cin >> rowsA;
    cout << "Enter columns for matrix A (= rows for matrix B): ";
    cin >> colsA;
    cout << "Enter columns for matrix B: ";
    cin >> colsB;

    cout << "Matrix A:" << endl;
    readMatrix(ma, rowsA, colsA);
    cout << "Matrix B:" << endl;
    readMatrix(mb, colsA, colsB);

    multiplyMatrices(ma, mb, rowsA, colsA, colsB, productResult);
    cout << "Product Matrix:" << endl;
    printMatrix(productResult, rowsA, colsB);

    return 0;
}