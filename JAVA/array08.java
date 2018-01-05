package array;

import java.util.Arrays;
import java.util.Comparator;

/*
 * 输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
 * 例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。
 */
public class array08 {
	public static void main(String[] args)
	{
		int[] a = {3,32,321};
		//int[] b = {1,2,3};
		System.out.println(PrintMinNumber(a));
	}
	public static String PrintMinNumber(int[] numbers)
	{
		String result = "";
		String[] numstr = new String[numbers.length];
		String temp = "";
		for (int i = 0; i < numbers.length; ++i)
		{
			temp = String.valueOf(numbers[i]);
			numstr[i] = temp;
		}
		Arrays.sort(numstr, new myComparator());
		for (int i = 0; i < numstr.length; ++i)
		{
			result += numstr[i];
		}
		return result;
    }
	
	public static class myComparator implements Comparator<String>
	{
		@Override
		public int compare(String o1, String o2)
		{
			int num1 = (int) (Integer.valueOf(o1)*Math.pow(10, o2.length()) + Integer.valueOf(o2));
			int num2 = (int) (Integer.valueOf(o2)*Math.pow(10, o1.length()) + Integer.valueOf(o1));
			if (num1 < num2)
			{
				return -1;
			}
			else  if (num1 == num2)
			{
				return 0;
			}
			else
			{
				return 1;
			}
		}
	}
}
