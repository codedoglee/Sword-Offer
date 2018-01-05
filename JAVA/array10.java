package array;
/*
 * 在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组,
 * 求出这个数组中的逆序对的总数P。并将P对1000000007取模的结果输出。 即输出P%1000000007
 */
public class array10 {
	public static void main(String[] args)
	{
		
	}
	public int InversePairs(int[] array)
	{
        if (array == null || array.length == 0)
        {
        	return 0;
        }
        int[] copy = new int[array.length];
        for (int i = 0; i < array.length; ++i)
        {
        	copy[i] = array[i];
        }
        int count = (int) InversePairsCore(array, copy, 0, array.length - 1);
        return count;
    }
	public long InversePairsCore(int[] array, int[] copy, int start, int end)
	{
		if (start == end)
		{
			copy[start] = array[start];
			return 0;
		}
		int length = (end - start) / 2;
		long left = InversePairsCore(copy, array, start, start + length);
		long right = InversePairsCore(copy, array, start + length + 1, end);
		
		int i = start + length;
		int j = end;
		int indexcopy = end;
		long count = 0;
		while (i >= start && j >= start + length + 1)
		{
			if (array[i] > array[j])
			{
				copy[indexcopy--] = array[i--];
				count += j - start - length;
			}
			else
			{
				copy[indexcopy--] = array[j--];
			}
		}
		for (; i >= start; --i)
		{
			copy[indexcopy--] = array[i];
		}
		for (; j >= start + length + 1; --j)
		{
			copy[indexcopy--] = array[j];
		}
		return (left + right + count) % 1000000007;
	}
}
