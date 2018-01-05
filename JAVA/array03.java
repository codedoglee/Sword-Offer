package array;
/*
 * ����һ���������飬ʵ��һ�����������������������ֵ�˳��ʹ�����е�����λ�������ǰ�벿�֣�
 * ���е�ż��λ��λ������ĺ�벿�֣�����֤������������ż����ż��֮������λ�ò��䡣
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
        //����λ��
        int odd = 1;
        //ż��λ��
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
