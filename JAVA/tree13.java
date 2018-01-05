package tree;

import java.util.ArrayList;

/*
 * 把二叉树打印成多行
 * 从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。
 */
public class tree13 {
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
	@SuppressWarnings("unchecked")
	ArrayList<ArrayList<Integer>> Print(TreeNode pRoot)
	{
		ArrayList<ArrayList<Integer>> result = new ArrayList<ArrayList<Integer>>();
		ArrayList<Integer> row = new ArrayList<Integer>();
		ArrayList<TreeNode> rowNode = new ArrayList<TreeNode>();
		if (pRoot == null)
		{
			return result;
		}
		row.add(pRoot.val);
		rowNode.add(pRoot);
		result.add((ArrayList<Integer>) row.clone());
		while (true)
		{
			int size = row.size();
			for (int j = 0; j < size; ++j)
			{
				TreeNode node = rowNode.get(0);
				if (node.left != null)
				{
					rowNode.add(node.left);
					row.add(node.left.val);
				}
				if (node.right != null)
				{
					rowNode.add(node.right);
					row.add(node.right.val);
				}
				rowNode.remove(0);
				row.remove(0);
			}
			if (row.isEmpty())
			{
				break;
			}
			result.add((ArrayList<Integer>) row.clone());
		}
		return result;
    }
}
