package array;
/*
 * ��һ������Ϊn����������������ֶ���0��n-1�ķ�Χ�ڡ� ������ĳЩ�������ظ��ģ�����֪���м����������ظ��ġ�Ҳ��֪��ÿ�������ظ����Ρ�
 * ���ҳ�����������һ���ظ������֡� ���磬������볤��Ϊ7������{2,3,1,0,2,5,3}����ô��Ӧ��������ظ�������2����3��
 */
public class array13 {
	public static void main(String[] args)
	{
		int[] a = {2,3,1,0,2,5,3};
		int[] result = new int[1];
		duplicate(a, 7, result);
		System.out.println(result[0]);
	}
	public static boolean duplicate(int[] numbers, int length, int[] duplication)
	{
	    if (numbers == null || length <= 0)
	    {
	    	return false;
	    }
	    int i = 0;
	    while (i < length)
	    {
	    	if (numbers[i] != i)
	    	{
	    		if (numbers[i] == numbers[numbers[i]])
	    		{
	    			duplication[0] = numbers[i];
	    			return true;
	    		}
	    		int temp = numbers[i];
	    		numbers[i] = numbers[temp];
	    		numbers[temp] = temp;
	    		continue;
	    	}
	    	else
	    	{
	    		i++;
	    	}
	    }
	    return false;
    }
}
