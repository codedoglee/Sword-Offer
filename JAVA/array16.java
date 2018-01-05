package array;

import java.util.Arrays;

/*
 * �����е�·��
 * �����һ�������������ж���һ���������Ƿ����һ������ĳ�ַ��������ַ���·����
 * ·�����ԴӾ����е�����һ�����ӿ�ʼ��ÿһ�������ھ������������ң����ϣ������ƶ�һ�����ӡ�
 * ���һ��·�������˾����е�ĳһ�����ӣ����·�������ٽ���ø��ӡ� 
 * ���� a b c e s f c s a d e e �����а���һ���ַ���"bcced"��·�������Ǿ����в�����"abcb"·����
 * ��Ϊ�ַ����ĵ�һ���ַ�bռ���˾����еĵ�һ�еڶ�������֮��·�������ٴν���ø��ӡ�
 */
public class array16 {
	public static void main(String[] args)
	{
		System.out.println(hasPath("ABCESFCSADEE".toCharArray(), 3, 4, "ABCB".toCharArray()));
	}
	public static boolean hasPath(char[] matrix, int rows, int cols, char[] str)
    {
		if (matrix == null || matrix.length == 0 || rows < 0 || cols < 0 || str == null || str.length == 0
			|| str.length > matrix.length || matrix.length != rows * cols)
		{
			return false;
		}
		int[] visited = new int[rows * cols];
		Arrays.fill(visited, 0);
		PathLength pathLength = new PathLength(0);
		for (int r = 0; r < rows; ++r)
		{
			for (int c = 0; c < cols; ++c)
			{
				if (hasPathCore(matrix, rows, cols, str, r, c, pathLength, visited))
				{
					return true;
				}
			}
		}
		return false;
    }
	public static class PathLength
	{
		int pathLength;
		public PathLength(int pl)
		{
			pathLength = pl;
		}
	}
	public static boolean hasPathCore(char[] matrix, int rows, int cols, char[] str, int row, int col, PathLength pl, int[] visited)
	{
		if (pl.pathLength >= str.length)
		{
			return true;
		}
		boolean hasPath = false;
		if (row >= 0 && row < rows && col >= 0 && col < cols && matrix[row * cols + col] == str[pl.pathLength] && visited[row * cols + col] == 0)
		{
			++pl.pathLength;
			visited[row * cols + col] = 1;
			hasPath = hasPathCore(matrix, rows, cols, str, row, col-1, pl, visited)
					|| hasPathCore(matrix, rows, cols, str, row, col+1, pl, visited) 
					|| hasPathCore(matrix, rows, cols, str, row-1, col, pl, visited) 
					|| hasPathCore(matrix, rows, cols, str, row+1, col, pl, visited);
			if (!hasPath)
			{
				--pl.pathLength;
				visited[row * cols + col] = 0;
			}
		}
		return hasPath;
	}
}
