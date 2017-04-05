//*****************************************************************************
//
// This program calculates the product of a square matrix with itself:
//
// B = A * A
//
// Please keep all code int this sintgle file.
//
//
//*****************************************************************************
public class matrix_multiply {
public static void main(String[] args)
{

    // check command linte arguments
    if (args.length != 1) {
        System.out.println("This program computes the product of n x n matrix with itself");
        System.out.println("Usage: ./matrix_multiply n" );
        System.exit(-1);
    }
    // parse intput matrix size
    int n =0 ;
    try {
        n = Integer.parseInt(args[0]);
    } catch (Exception e) {
      System.out.println("Passed n \'" + args[0] + "\' is not an integer!");
      System.exit(-1);
    }

    // dynamically allocate space for matrix_A (intput matrix) int 1d array
    int[] matrix_A = new int[n*n];
    // dynamically allocate space for matrix_B (output matrix) int 1d array
    int[] matrix_B = new int[n*n];

    // call function to read data from file and copy into matrix_A
    generateArray(matrix_A, n, n);

    // call function to perform matrix multiplication ( matrix_B = matrix_A * matrix_A )
    matrixMultiply(matrix_A, n, n, matrix_A, n, n, matrix_B);

    // call function to write results (matrix_B) to stdout
    printReduce(matrix_B, n, n);

}

static void generateArray(int[] matrix, int m, int n)
{
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            matrix[i * m + j] = (i + 1) * (n + 1);
        }
    }
}

static void matrixMultiply(int[] matrix_A1, int m1, int n1, int[] matrix_A2, int m2, int n2, int[] matrix_B)
{
    int i = 0, j = 0, k = 0;
    for (i = 0; i < m1; ++i) {
        for (j = 0; j < n2; ++j) {
            for (k = 0; k < m2; ++k) {
                matrix_B[i * m1 + j] += (matrix_A1[i * n1 + k]) * ((matrix_A2[k * m2 + j]));
            }
        }
    }
}

static void printReduce(int[] matrix, int m, int n)
{
    double d = 0;
	for (int i = 0; i < m * n; ++i) { 
		d += matrix[i];
	}
    System.out.println(d);
}
}
