package array;

import java.util.ArrayList;

/*
 * ����n���������ҳ�������С��K��������������4,5,1,6,2,7,3,8��8�����֣�����С��4��������1,2,3,4,
 */
public class array06 {
	public static void main(String[] args)
	{
		int[] a = {4,5,1,6,2,7,3,8};
		System.out.println(GetLeastNumbers_Solution(a, 4));
	}
	public static ArrayList<Integer> GetLeastNumbers_Solution(int[] input, int k)
	{
		ArrayList<Integer> mink = new ArrayList<Integer>();
		if (input == null || input.length < k || k <= 0)
		{
			return mink;
		}
		int max = input[0];
		for (int i = 0; i < k; i++)
		{
			mink.add(input[i]);
			if (input[i] > max)
			{
				max = input[i];
			}
		}
		for (int i = k; i < input.length; ++i)
		{
			if (input[i] < max)
			{
				mink.remove((Object)max);
				mink.add(input[i]);
				max = input[i];
				for (int j = 0; j < k; ++j)
				{
					if (mink.get(j) > max)
					{
						max = mink.get(j);
					}
				}
			}
		}
		return mink;
    }
}
