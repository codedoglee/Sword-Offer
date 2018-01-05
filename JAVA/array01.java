package array;
/*
 * 在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
 * 请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
 * 
 * 关键思路：从矩阵左下角开始查找，遇大上移，遇小右移
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
