package other;

import java.util.ArrayList;

/*
 * 输入一个递增排序的数组和一个数字S，在数组中查找两个数，使得他们的和正好是S，如果有多对数字的和等于S，输出两个数的乘积最小的。 
 */
public class other09 {
	public static void main(String[] args)
	{
		int[] a = {1,2,4,7,11,15};
		int b = 15;
		System.out.println(FindNumbersWithSum(a, b));
	}
	public static ArrayList<Integer> FindNumbersWithSum(int[] array, int sum)
	{
		ArrayList<Integer> result = new ArrayList<Integer>();
        if (array == null || array.length <= 1)
        {
        	return result;
        }
        int length = array.length;
        int i = 0;
        int j = length-1;
        while (i < j)
        {
        	if (array[i] + array[j] == sum)
            {
            	if (result.isEmpty())
            	{
            		result.add(array[i]);
            		result.add(array[j]);
            	}
            	else if (array[i] * array[j] < result.get(0) * result.get(1))
            	{
            		result.set(0, array[i]);
            		result.set(1, array[j]);
            	}
            	++i;
            }
        	else if (array[i] + array[j] < sum)
        	{
        		++i;
        	}
        	else
        	{
        		--j;
        	}
        }
        return result;
    }
}
