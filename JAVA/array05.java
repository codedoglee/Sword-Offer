package array;

import java.util.Arrays;

/*
 * 数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。
 * 由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。
 * 
 * 解法1：对数组进行排序，并获得数组的中位数，然后遍历数组，找到该数字的头和尾，其长度大于数组长度的一半，输出该数字，否则输出0.
 * 解法2：遍历一遍的O(n)解法，数组中有一个数字出现次数超过数组长度一半，也就是说他出现的次数比其他数字出现的次数的和还要多。
 */
public class array05 {
	public static void main(String[] args)
	{
		int[] a = {2,1,2,3,2,4,2,2,5};
		System.out.println(MoreThanHalfNum_Solution2(a));
	}
	public static int MoreThanHalfNum_Solution(int[] array)
	{
		if (array == null || array.length == 0)
		{
			return 0;
		}
        Arrays.sort(array);
        int target = array[array.length >> 1];
        int i = 0;
        for (; i < array.length; ++i)
        {
        	if (array[i] == target)
        	{
        		break;
        	}
        }
        int j = i;
        while (j < array.length && array[j] == target)
        {
        	++j;
        }
        if (j-i > array.length>>1)
        {
        	return target;
        }
        return 0;
    }
	public static int MoreThanHalfNum_Solution2(int[] array)
	{
		if (array == null || array.length == 0)
		{
			return 0;
		}
		int times = 1;
		int result = array[0];
        for (int i = 1; i < array.length; ++i)
        {
        	if (times == 0)
    		{
    			times = 1;
    			result = array[i];
    		}
        	if (array[i] != result)
        	{
        		times--;
        	}
        	else
        	{
        		times++;
        	}
        }
        int count = 0;
        for (int i = 0; i < array.length; ++i)
        {
        	if (array[i] == result)
        	{
        		++count;
        	}
        }
        if (count > array.length >> 1)
        {
        	return result;
        }
        return 0;
    }
}
