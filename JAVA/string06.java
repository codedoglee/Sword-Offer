package string;

import java.util.Arrays;

/*
 * LL���������ر��,��Ϊ��ȥ����һ���˿���,���������Ȼ��2������,2��С��(һ����ԭ����54��^_^)...��������г����5����,
 * �����Լ�������,�����ܲ��ܳ鵽˳��,����鵽�Ļ�,������ȥ��������Ʊ,�ٺ٣���������A,����3,С��,����,��Ƭ5��,
 * ��Oh My God!������˳��.....LL��������,��������,������\С �����Կ����κ�����,����A����1,JΪ11,QΪ12,KΪ13��
 * �����5���ƾͿ��Ա�ɡ�1,2,3,4,5��(��С���ֱ���2��4),��So Lucky!����LL����ȥ��������Ʊ���� ����,Ҫ����ʹ�������ģ������Ĺ���,
 * Ȼ���������LL��������Ρ�Ϊ�˷������,�������Ϊ��С����0��
 */
public class string06 {
	public static void main(String[] args)
	{
		
	}
	public boolean isContinuous(int[] numbers)
	{
		if (numbers == null || numbers.length <= 0)
		{
			return false;
		}
		Arrays.sort(numbers);
		int length = numbers.length;
		int i = 0;
		while (numbers[i] == 0)
		{
			++i;
		}
		//����0֮�ⲻ�����ظ�������
		for (int j = i; j < length-1; ++j)
		{
			if (numbers[j] == numbers[j+1])
			{
				return false;
			}
		}
		if (numbers[length-1] - numbers[i] + 1 <= length)
		{
			return true;
		}
		else
		{
			return false;
		}
    }
}
