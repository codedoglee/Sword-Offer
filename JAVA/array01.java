package array;
/*
 * ��һ����ά�����У�ÿһ�ж����մ����ҵ�����˳������ÿһ�ж����մ��ϵ��µ�����˳������
 * �����һ������������������һ����ά�����һ���������ж��������Ƿ��и�������
 * 
 * �ؼ�˼·���Ӿ������½ǿ�ʼ���ң��������ƣ���С����
 */
public class array01 {
	public boolean Find(int[][] array, int target)
	{
		if (array == null || array.length == 0 || array[0].length == 0)
		{
			return false;
		}
		int row = array.length;
		int col = array.length;
		int i = row-1;
		int j = 0;
		while (i >= 0 && j < col)
		{
			if (array[i][j] == target)
			{
				return true;
			}
			else if (array[i][j] < target)
			{
				++j;
			}
			else
			{
				--i;
			}
		}
		return false;
	}
	public static void main(String[] args)
	{
		
	}
}
