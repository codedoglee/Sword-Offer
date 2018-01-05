package array;

//import java.util.ArrayList;
/*
 * 把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
 * 输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。
 * 例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。
 * NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
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
