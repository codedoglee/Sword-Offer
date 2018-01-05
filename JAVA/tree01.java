package tree;
/*
 * 重建二叉树
 * 输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
 * 例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
 */
public class tree01 {
	public static class TreeNode {
		int val;
		TreeNode left;
		TreeNode right;
		TreeNode(int x)
		{
			val = x;
		}
	}
	public static TreeNode reConstructBinaryTree(int[] pre, int[] in)
	{
		if (pre == null || in == null || pre.length == 0 || in.length == 0)
		{
			return null;
		}
		return constructor(pre, in);
	}
	public static TreeNode constructor(int[] pre, int[] in)
	{
		if (pre.length == 0 || in.length == 0)
		{
			return null;
		}
		TreeNode root = new TreeNode(pre[0]);
		int index = 0;
		for (int i = 0; i < in.length; ++i)
		{
			if (in[i] == pre[0])
			{
				index = i;
				break;
			}
			continue;
		}
		int[] leftpre = new int[index];
		int[] rightpre = new int[pre.length-index-1];
		int[] leftin = new int[index];
		int[] rightin = new int[pre.length-index-1];
		for (int z = 0; z < index; ++z)
		{
			leftpre[z] = pre[z+1];
			leftin[z] = in[z];
		}
		for (int z = 0; z < pre.length-index-1; ++z)
		{
			rightpre[z] = pre[index+1+z];
			rightin[z] = in[index+1+z];
		}
		root.left = constructor(leftpre, leftin);
		root.right = constructor(rightpre, rightin);
		return root;
	}
}
