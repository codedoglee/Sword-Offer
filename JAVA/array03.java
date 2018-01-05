package array;
/*
 * 输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，
 * 所有的偶数位于位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。
 */
public class array03 {
	public static void main(String[] args)
	{
		int[] a = {1,2,7,5,8,6,3,4,2,9};
		reOrderArray(a);
		for (int i = 0; i < a.length; i++)
		{
			System.out.printf("%4d", a[i]);
		}
	}
	public static void reOrderArray(int[] array)
	{
        if (array == null || array.length == 0 || array.length == 1)
        {
        	return;
        }
        //奇数位置
        int odd = 1;
        //偶数位置
        int even = 0;
        int len = array.length;
        while (odd < len)
        {
        	if (array[even] % 2 == 0)
        	{
        		if (array[odd] % 2 == 0)
        		{
        			++odd;
        		}
        		else
        		{
        			for (int i = odd; i > even; --i)
        			{
        				int temp = array[i];
                		array[i] = array[i-1];
                		array[i-1] = temp;
        			}
        			++odd;
        			++even;
        		}
        	}
        	else
        	{
        		++odd;
    			++even;
        	}
        }
    }
}
