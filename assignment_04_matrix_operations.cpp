// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
using namespace std;

const int MAX_SIZE = 10;

void readMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

void printMatrix(const int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}

void transposeMatrix(const int src[MAX_SIZE][MAX_SIZE], int dest[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            dest[j][i] = src[i][j];
        }
    }
}

void addMatrices(const int A[MAX_SIZE][MAX_SIZE], const int B[MAX_SIZE][MAX_SIZE], int C[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void multiplyMatrices(const int A[MAX_SIZE][MAX_SIZE], const int B[MAX_SIZE][MAX_SIZE], int C[MAX_SIZE][MAX_SIZE], int M, int N, int P) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < P; j++) {
            C[i][j] = 0;
            for (int k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int A[MAX_SIZE][MAX_SIZE];
    int B[MAX_SIZE][MAX_SIZE];
    int C[MAX_SIZE][MAX_SIZE];

    cout << "--- PART A: Transpose Matrix ---" << endl;
    int rowsA, colsA;
    cout << "Enter number of rows: ";
    cin >> rowsA;
    cout << "Enter number of columns: ";
    cin >> colsA;

    readMatrix(A, rowsA, colsA);

    cout << "\nOriginal Matrix:" << endl;
    printMatrix(A, rowsA, colsA);

    transposeMatrix(A, C, rowsA, colsA);

    cout << "\nTransposed Matrix:" << endl;
    printMatrix(C, colsA, rowsA);

    cout << "\n--- PART B: Add Two Matrices ---" << endl;
    int rowsB, colsB;
    cout << "Enter number of rows for Matrix 1: ";
    cin >> rowsA;
    cout << "Enter number of columns for Matrix 1: ";
    cin >> colsA;

    cout << "Enter elements for Matrix 1:" << endl;
    readMatrix(A, rowsA, colsA);

    cout << "Enter number of rows for Matrix 2: ";
    cin >> rowsB;
    cout << "Enter number of columns for Matrix 2: ";
    cin >> colsB;

    if (rowsA != rowsB || colsA != colsB) {
        cout << "Error: Matrices must have the same dimensions for addition." << endl;
    } else {
        cout << "Enter elements for Matrix 2:" << endl;
        readMatrix(B, rowsB, colsB);

        addMatrices(A, B, C, rowsA, colsA);

        cout << "\nMatrix Sum (A + B):" << endl;
        printMatrix(C, rowsA, colsA);
    }

    cout << "\n--- PART C: Multiply Two Matrices ---" << endl;
    int M, N, N2, P;
    cout << "Enter rows for Matrix A (M): ";
    cin >> M;
    cout << "Enter columns for Matrix A (N): ";
    cin >> N;

    cout << "Enter elements for Matrix A:" << endl;
    readMatrix(A, M, N);

    cout << "Enter rows for Matrix B (N): ";
    cin >> N2;
    cout << "Enter columns for Matrix B (P): ";
    cin >> P;

    if (N != N2) {
        cout << "Error: Columns of Matrix A must equal rows of Matrix B." << endl;
    } else {
        cout << "Enter elements for Matrix B:" << endl;
        readMatrix(B, N2, P);

        multiplyMatrices(A, B, C, M, N, P);

        cout << "\nMatrix Product (A x B):" << endl;
        printMatrix(C, M, P);
    }

    return 0;
}

