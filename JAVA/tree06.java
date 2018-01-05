package tree;

import java.util.ArrayList;

/*
 * ����һ�Ŷ�������һ����������ӡ���������н��ֵ�ĺ�Ϊ��������������·����·������Ϊ�����ĸ���㿪ʼ����һֱ��Ҷ����������Ľ���γ�һ��·����
 */
public class tree06 {
	public static void main(String[] args)
	{
		TreeNode root = new TreeNode(10);
		TreeNode node1 = new TreeNode(5);
		TreeNode node2 = new TreeNode(12);
		TreeNode node3 = new TreeNode(4);
		TreeNode node4 = new TreeNode(7);
		
		root.left = node1;
		root.right = node2;
		node1.left = node3;
		node1.right = node4;
		
		System.out.println(FindPath(root, 22));
	}
	public static class TreeNode {
	    int val = 0;
	    TreeNode left = null;
	    TreeNode right = null;

	    public TreeNode(int val) {
	        this.val = val;
	    }
	}
	public static ArrayList<ArrayList<Integer>> FindPath(TreeNode root, int target)
	{
		ArrayList<ArrayList<Integer>> result = new ArrayList<ArrayList<Integer>>();
        ArrayList<Integer> path = new ArrayList<Integer>();
        int sum = 0;
        FindPath(result, root, target, path, sum);
        return result;
    }
	@SuppressWarnings("unchecked")
	public static void FindPath(ArrayList<ArrayList<Integer>> result, TreeNode root, int target, ArrayList<Integer> path, int sum)
	{
        if (root == null)
        {
        	return;
        }
		sum += root.val;
		path.add(root.val);
		if (sum == target && root.left == null && root.right == null)
		{
			result.add((ArrayList<Integer>) path.clone());
		}
		if (root.left != null)
		{
			FindPath(result, root.left, target, path, sum);
		}
		if (root.right != null)
		{
			FindPath(result, root.right, target, path, sum);
		}
		path.remove(path.size() - 1);
	}
}
