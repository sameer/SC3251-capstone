/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
#include "nativeloop.h"
JNIEXPORT void JNICALL Java_nativeloop_nmult
  (JNIEnv * env, jclass thisClass, jintArray a, jdoubleArray b, jdouble m) {
	jint *aPtr = (jint *)(env)->GetPrimitiveArrayCritical(a, 0);
	jdouble *bPtr = (jdouble *)(env)->GetPrimitiveArrayCritical(b, 0);

	int i, j;
	double sum = 0;
	for (j = 0; j < nativeloop_ITER; ++j)
	for (i = 0; i < nativeloop_SIZE; ++i)
	{
		bPtr[i] = aPtr[i] * 3.14 + 25 * aPtr[i] + 10;
		sum += bPtr[i];
	}
	printf("%f\n", sum);
	(env)->ReleasePrimitiveArrayCritical(a, aPtr, 0);
	(env)->ReleasePrimitiveArrayCritical(b, bPtr, 0);
}
