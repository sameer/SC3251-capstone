#include <stdlib.h>
#include <stdio.h>
const static int SIZE = 1000000;
const static int ITER = 1000;
int main()
{
	int i;

	int *a = malloc(sizeof(int) * SIZE);
	for (i = 0; i < SIZE; ++i)
	{
		a[i] = 0;
	}

	double *b = malloc(sizeof(double) * SIZE);
	for (i = 0; i < SIZE; ++i)
	{
		b[i] = 0.0;
	}


	for (i = 0; i < SIZE; ++i)
	{
		a[i] = i;
	}

	int j;
	double sum = 0;
	for (j = 0; j < ITER; ++j)
	for (i = 0; i < SIZE; ++i)
	{
		b[i] = a[i] * 3.14 + 25 * a[i] + 10;
		sum += b[i];
	}

	printf("%f\n", sum);
	free(a);
	free(b);
	return 0;
}
