package other;
/*
 * ����һ��������������������Ʊ�ʾ��1�ĸ��������и����ò����ʾ��
 */
public class other05 {
	public static void main(String[] args)
	{
		System.out.println(NumberOf1(-1));
	}
	public static int NumberOf1(int n) {
		int count = 0;
		while (n != 0)
		{
			n = n & (n-1);
			count++;
		}
		return count;
    }
}
