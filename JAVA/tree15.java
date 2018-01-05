package tree;

import java.util.LinkedList;

/*
 * 二叉搜索树的第k个结点
 * 给定一颗二叉搜索树，请找出其中的第k小的结点。例如， 5 / \ 3 7 /\ /\ 2 4 6 8 中，按结点数值大小顺序第三个结点的值为4。
 */
public class tree15 {
	public static void main(String[] args)
	{
		
	}
	public class TreeNode {
	    int val = 0;
	    TreeNode left = null;
	    TreeNode right = null;

	    public TreeNode(int val) {
	        this.val = val;
	    }
	}
	TreeNode KthNode(TreeNode pRoot, int k)
    {
		if (pRoot == null || k <= 0)
		{
			return null;
		}
		LinkedList<TreeNode> travel = new LinkedList<TreeNode>();
		midTravel(pRoot, travel);
		if (k > travel.size())
		{
			return null;
		}
		return travel.get(k-1);
    }
	public void midTravel(TreeNode pRoot, LinkedList<TreeNode> res)
	{
		if (pRoot == null)
		{
			return;
		}
		else
		{
			midTravel(pRoot.left, res);
			res.add(pRoot);
			midTravel(pRoot.right, res);
		}
	}
}
