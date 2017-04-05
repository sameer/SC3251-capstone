const static int SIZE = 1000000;
const static int ITER = 1000;
int main()
{
	int *a = new int[SIZE];
	double *b = new double[SIZE];


	for (int i = 0; i < SIZE; ++i)
	{
		a[i] = i;
	}
	for (int i = 0; i < SIZE * ITER; ++i)
	{
		b[i % SIZE] = a[i % SIZE] * 3.14;
	}

	free(a);
	free(b);
	return 0;
}
