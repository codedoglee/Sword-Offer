package array;

/*
 * ��ֻ��������2��3��5��������������Ugly Number��������6��8���ǳ�������14���ǣ���Ϊ����������7��
 * ϰ�������ǰ�1�����ǵ�һ���������󰴴�С�����˳��ĵ�N��������
 */
public class array09 {
	public static void main(String[] args)
	{
		System.out.println(GetUglyNumber(900));
	}
	static int two = 2;
	static int three = 3;
	static int five = 5;
	public static int GetUglyNumber(int index)
	{
		if (index <= 0)
		{
			return 0;
		}
		if (index <= 6)
		{
			return index;
		}
		int[] ugly = new int[index];
		int i = 1;
		int j = 1;
		int k = 1;
		int z = 0;
		int a = 0, b = 0, c = 0;
		for (; z <= 4; ++z)
		{
			ugly[z] = z+1;
		}
		for (; z < index; ++z)
		{
			while (a <= ugly[z-1])
			{
				i++;
				a = two*ugly[i];
			}
			while (b <= ugly[z-1])
			{
				j++;
				b = three*ugly[j];
			}
			while (c <= ugly[z-1])
			{
				k++;
				c = five*ugly[k];
			}
			ugly[z] = Math.min(Math.min(a, b), c);
		}
        return ugly[index-1];
    }
}
