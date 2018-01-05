package array;

import java.util.Arrays;

/*
 * �����˻�����
 * ����һ������A[0,1,...,n-1],�빹��һ������B[0,1,...,n-1],����B�е�Ԫ��B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]������ʹ�ó�����
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
