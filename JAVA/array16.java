package array;

import java.util.Arrays;

/*
 * 矩阵中的路径
 * 请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。
 * 路径可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，向右，向上，向下移动一个格子。
 * 如果一条路径经过了矩阵中的某一个格子，则该路径不能再进入该格子。 
 * 例如 a b c e s f c s a d e e 矩阵中包含一条字符串"bcced"的路径，但是矩阵中不包含"abcb"路径，
 * 因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入该格子。
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
