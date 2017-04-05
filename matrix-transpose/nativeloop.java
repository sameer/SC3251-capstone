public class nativeloop
{
	static
	{
		System.loadLibrary("nativeloop");
	}
	static final int SIZE = 1000000;
	static final int ITER = 10000;
	static final int[] a = new int[SIZE];
	static final double[] b = new double[SIZE];
	public static void main(String[] args)
	{
		for (int i = 0; i < SIZE; ++i)
		{
			a[i] = i;
		}
		nmult(a, b, 3.14);
	}
	public static native void nmult(int[] a, double[]b, double m);
}
