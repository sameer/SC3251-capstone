//*****************************************************************************
//
// This program calculates the product of a square matrix with itself:
//
// B = A * A
//
// Please keep all code in this single file.
//
//
//*****************************************************************************

#include <iostream>
#include <stdio.h>

static void generateArray(int* matrix, int m, int n);
static void matrixMultiply(const int* matrix_A1, int n1, int m1, const int* matrix_A2, int n2, int m2, int* matrix_B);
static void printReduce(const int* matrix, int m, int n);
static int* matrixTranspose(const int* matrix, int m, int n);

int main(int argc, char** argv)
{

    // check command line arguments
    if (argc != 2) {
        std::cout << "This program computes the product of n x n matrix with itself" << std::endl;
        std::cout << "Usage: ./matrix_multiply n" << std::endl;
        return -1;
    }
    for (int i = 0; argv[1][i] != '\0'; ++i) {
        if (!isdigit(argv[1][i])) {
            std::cout << "Argument n \'"<< argv[1] <<"\' is not a number!" << std::endl;
            return -1;
        }
    }

    // parse input matrix size
    int n;
    sscanf(argv[1], "%d", &n);

    // dynamically allocate space for matrix_A (input matrix) in 1d array
    int *matrix_A = new int[n*n];
    // dynamically allocate space for matrix_B (output matrix) in 1d array
    int *matrix_B = new int[n*n];

    // call function to read data from file and copy into matrix_A
    generateArray(matrix_A, n, n);

    // call function to perform matrix multiplication ( matrix_B = matrix_A * matrix_A )
    matrixMultiply(matrix_A, n, n, matrix_A, n, n, matrix_B);

    // call function to write results (matrix_B) to stdout
    printReduce(matrix_B, n, n);

    delete[] matrix_A;
    delete[] matrix_B;
    return 0;
}

static void generateArray(int* matrix, int m, int n)
{
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            matrix[i * m + j] = (i + 1) * (n + 1);
        }
    }
}

static void matrixMultiply(const int* matrix_A1, int m1, int n1, const int* matrix_A2, int m2, int n2, int* matrix_B)
{
    matrix_A2 = matrixTranspose(matrix_A2, m2, n2);
    #pragma omp parallel for schedule(dynamic) shared(matrix_A1, matrix_A2, matrix_B)
    for (int i = 0; i < m1; ++i) {
        for (int j = 0; j < n2; ++j) {
            for (int k = 0; k < m2; ++k) {
                matrix_B[i * m1 + j] += (matrix_A1[i * n1 + k]) * ((matrix_A2[j * n2 + k]));
            }
        }
    }
    delete[] matrix_A2;
}

static void printReduce(const int* matrix, int m, int n)
{
    double d = 0;
	for (int i = 0; i < m * n; ++i) { 
		d += matrix[i];
	}
    std::cout << d << std::endl;
}

static int* matrixTranspose(const int* matrix, int m, int n)
{
    int* matrixT = new int[m*n];
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            matrixT[j * n + i] = matrix[i * m + j];
        }
    }
    return matrixT;
}
