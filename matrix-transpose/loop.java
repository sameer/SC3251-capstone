public class loop
{
	static final int SIZE = 1000000;
	static final int ITER = 10000;
	public static void main(String[] args)
	{
		int[] a = new int[SIZE];
		double[] b = new double[SIZE];
		for (int i = 0; i < SIZE; ++i)
		{
			a[i] = i;
		}

		for (int j = 0; j < ITER; ++j)
			mult(a, b, 3.14);
	}

	public static void mult(int[] a, double[] b, double m)
	{
		for (int i = 0; i < SIZE; ++i)
		{
			b[i] = a[i] * m;
		}
	}
}
