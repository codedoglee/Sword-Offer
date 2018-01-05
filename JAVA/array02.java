package array;

//import java.util.ArrayList;
/*
 * ��һ�������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ�����ǳ�֮Ϊ�������ת��
 * ����һ���ǵݼ�����������һ����ת�������ת�������СԪ�ء�
 * ��������{3,4,5,1,2}Ϊ{1,2,3,4,5}��һ����ת�����������СֵΪ1��
 * NOTE������������Ԫ�ض�����0���������СΪ0���뷵��0��
 */
public class array02
{
	public static void main(String[] args)
	{
		int[] a = {2,1,1,1,1};
		System.out.println(minNumberInRotateArray(a));
	}
	public static int minNumberInRotateArray(int[] array)
	{
	    if (array == null || array.length == 0)
	    {
	    	return 0;
	    }
	    int len = array.length;
	    int low = 0;
	    int high = len-1;
	    int mid = 0;
	    while (low <= high)
	    {
	    	if (low == high)
	    	{
	    		return array[low];
	    	}
	    	mid = (low + high) / 2;
	    	if (array[mid] >= array[low] && array[mid] <= array[high])
	    	{
	    		return array[low];
	    	}
	    	else if (array[mid] <= array[low] && array[mid] <= array[high])
	    	{
	    		high = mid;
	    	}
	    	else if (array[mid] >= array[low] && array[mid] >=array[high])
	    	{
	    		low = mid + 1;
	    	}
	    }
	    return 0;
    }
}
