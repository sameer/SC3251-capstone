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
public class openmpnativematrix_multiply {
static
{
    System.loadLibrary("openmpmatrix_multiply");
}
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

static native void generateArray(int[] matrix, int m, int n);

static native void matrixMultiply(int[] matrix_A1, int m1, int n1, int[] matrix_A2, int m2, int n2, int[] matrix_B);

static native void printReduce(int[] matrix, int m, int n);
}
