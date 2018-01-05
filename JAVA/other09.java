package other;

import java.util.ArrayList;

/*
 * ����һ����������������һ������S���������в�����������ʹ�����ǵĺ�������S������ж�����ֵĺ͵���S������������ĳ˻���С�ġ� 
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
