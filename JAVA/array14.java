package array;

import java.util.Arrays;

/*
 * 构建乘积数组
 * 给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。不能使用除法。
 */
public class array14 {
	public static void main(String[] args)
	{

	}
	public int[] multiply(int[] A)
	{
		if (A == null || A.length == 0)
		{
			return null;
		}
		int length = A.length;
		int[] result = new int[length];
		Arrays.fill(result, 1);
		int[][] help = new int[length][length];
		for (int i = 0; i < length; ++i)
		{
			help[i] = A.clone();
		}
		for (int i = 0; i < length; ++i)
		{
			help[i][i] = 1;
		}
		for (int i = 0; i < length; ++i)
		{
			for (int j = 0; j < length; ++j)
			{
				result[i] *= help[i][j];
			}
		}
		return result;
    }
}
