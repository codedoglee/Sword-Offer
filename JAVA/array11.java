package array;
/*
 * 统计一个数字在排序数组中出现的次数。
 */
public class array11 {
	public static void main(String[] args)
	{

	}
	public int GetNumberOfK(int[] array, int k)
	{
		if (array == null || array.length == 0 || k < array[0] || k > array[array.length-1])
		{
			return 0;
		}
		int length = array.length;
		int low = 0;
		int high = length-1;
		int middle = (low + high) / 2;
		while (low <= high)
		{
			if (array[middle] == k)
			{
				break;
			}
			else if (array[middle] > k)
			{
				high = middle-1;
			}
			else
			{
				low = middle+1;
			}
			middle = (low + high) / 2;
		}
		int i = middle;
		int j = middle;
		if (array[middle] == k)
		{
			while (i < length && array[i] == k)
			{
				i++;
			}
			while (j >= 0 && array[j] == k)
			{
				j--;
			}
			return i-j-1;
		}
		else
		{
			return 0;
		}
    }
}
