package array;

import java.util.ArrayList;

/*
 * 输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，
 * 例如，如果输入如下矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 
 * 则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
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
			//打印第一行
			for (; col <= maxcol; ++col)
			{
				result.add(matrix[row][col]);
			}
			++minrow;
			--col;
			if (minrow <= maxrow)
			{
				//打印最后一列
				for (++row; row <= maxrow; ++row)
				{
					result.add(matrix[row][col]);
				}
				--maxcol;
				--row;
				
				if (mincol <= maxcol)
				{
					//打印最后一行
					for (--col; col >= mincol; --col)
					{
						result.add(matrix[row][col]);
					}
					--maxrow;
					++col;
					
					if (minrow <= maxrow)
					{
						//打印第一列
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
