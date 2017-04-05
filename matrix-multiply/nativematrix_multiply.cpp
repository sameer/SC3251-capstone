#include "nativematrix_multiply.h"
/*
 * Class:     nativematrix_multiply
 * Method:    generateArray
 * Signature: ([III)V
 */
JNIEXPORT void JNICALL Java_nativematrix_1multiply_generateArray
  (JNIEnv *env, jclass thisClass, jintArray jMatrix, jint m, jint n)
{
	jint *matrix = (jint*) env->GetPrimitiveArrayCritical(jMatrix, 0);
	for (jint i = 0; i < m; ++i) {
            for (jint j = 0; j < n; ++j) {
                matrix[i * m + j] = (i + 1) * (n + 1);
            }
        }
	env->ReleasePrimitiveArrayCritical(jMatrix, matrix, 0);
}

/*
 * Class:     nativematrix_multiply
 * Method:    matrixMultiply
 * Signature: ([III[III[I)V
 */
JNIEXPORT void JNICALL Java_nativematrix_1multiply_matrixMultiply
  (JNIEnv *env, jclass thisClass, jintArray jMatrix_A1, jint m1, jint n1, jintArray jMatrix_A2, jint m2, jint n2, jintArray jMatrix_B)
{
	jint *matrix_A1 = (jint*) env->GetPrimitiveArrayCritical(jMatrix_A1, 0);
	jint *matrix_A2 = (jint*) env->GetPrimitiveArrayCritical(jMatrix_A2, 0);
	jint *matrix_B  = (jint*) env->GetPrimitiveArrayCritical(jMatrix_B, 0);
	for (jint i = 0; i < m1; ++i) {
            for (jint j = 0; j < n2; ++j) {
                for (jint k = 0; k < m2; ++k) {
                    matrix_B[i * m1 + j] += (matrix_A1[i * n1 + k]) * ((matrix_A2[k * m2 + j]));
                }
            }
        }
	env->ReleasePrimitiveArrayCritical(jMatrix_A1, matrix_A1, 0);
	env->ReleasePrimitiveArrayCritical(jMatrix_A2, matrix_A2, 0);
	env->ReleasePrimitiveArrayCritical(jMatrix_B, matrix_B, 0);
}

/*
 * Class:     nativematrix_multiply
 * Method:    printReduce
 * Signature: ([III)V
 */
JNIEXPORT void JNICALL Java_nativematrix_1multiply_printReduce
  (JNIEnv *env, jclass thisClass, jintArray jMatrix, jint m, jint n)
{
	jint *matrix = (jint*) env->GetPrimitiveArrayCritical(jMatrix, 0);
	jdouble d = 0;
	for (jint i = 0; i < m * n; ++i) {
            d += matrix[i];
        }
	printf("%f\n", d);
	env->ReleasePrimitiveArrayCritical(jMatrix, matrix, 0);
}
