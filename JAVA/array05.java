package array;

import java.util.Arrays;

/*
 * ��������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�룬���ҳ�������֡���������һ������Ϊ9������{1,2,3,2,2,2,5,4,2}��
 * ��������2�������г�����5�Σ��������鳤�ȵ�һ�룬������2����������������0��
 * 
 * �ⷨ1��������������򣬲�����������λ����Ȼ��������飬�ҵ������ֵ�ͷ��β���䳤�ȴ������鳤�ȵ�һ�룬��������֣��������0.
 * �ⷨ2������һ���O(n)�ⷨ����������һ�����ֳ��ִ����������鳤��һ�룬Ҳ����˵�����ֵĴ������������ֳ��ֵĴ����ĺͻ�Ҫ�ࡣ
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
