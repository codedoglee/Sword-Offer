package tree;

import java.util.LinkedList;

/*
 * �����������ĵ�k�����
 * ����һ�Ŷ��������������ҳ����еĵ�kС�Ľ�㡣���磬 5 / \ 3 7 /\ /\ 2 4 6 8 �У��������ֵ��С˳�����������ֵΪ4��
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
