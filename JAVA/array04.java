package array;

import java.util.ArrayList;

/*
 * ����һ�����󣬰��մ���������˳ʱ���˳�����δ�ӡ��ÿһ�����֣�
 * ���磬����������¾��� 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 
 * �����δ�ӡ������1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
 */
public class array04 {
	public static void main(String[] args)
	{
		//int[][] a = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16}};
		int[][] b = {{1}, {2}, {3}, {4}, {5}};
		ArrayList<Integer> res = new ArrayList<Integer>();
		res = printMatrix(b);
		System.out.println(res);
	}
	public static ArrayList<Integer> printMatrix(int[][] matrix)
	{
		if (matrix == null || matrix.length == 0 || matrix[0].length == 0)
		{
			return null;
		}
		ArrayList<Integer> result = new ArrayList<Integer>();
		int row = 0;
		int col = 0;
		int maxrow = matrix.length - 1;
		int minrow = 0;
		int maxcol = matrix[0].length - 1;
		int mincol = 0;
		
		while (minrow <= maxrow && mincol <= maxcol)
		{
			//��ӡ��һ��
			for (; col <= maxcol; ++col)
			{
				result.add(matrix[row][col]);
			}
			++minrow;
			--col;
			if (minrow <= maxrow)
			{
				//��ӡ���һ��
				for (++row; row <= maxrow; ++row)
				{
					result.add(matrix[row][col]);
				}
				--maxcol;
				--row;
				
				if (mincol <= maxcol)
				{
					//��ӡ���һ��
					for (--col; col >= mincol; --col)
					{
						result.add(matrix[row][col]);
					}
					--maxrow;
					++col;
					
					if (minrow <= maxrow)
					{
						//��ӡ��һ��
						for (--row; row >= minrow; --row)
						{
							result.add(matrix[row][col]);
						}
						++mincol;
						++row;
					}
				}
			}
			++col;
		}
		return result;
    }
}
