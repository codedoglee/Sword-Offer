package tree;

import java.util.ArrayList;
import java.util.concurrent.LinkedBlockingQueue;
/*
 * �������´�ӡ����������ÿ���ڵ㣬ͬ��ڵ�������Ҵ�ӡ��
 */
public class tree04 {
	public static void main(String[] args)
	{
		TreeNode root = null;
		System.out.println(PrintFromTopToBottom(root));
	}
	public class TreeNode {
	    int val = 0;
	    TreeNode left = null;
	    TreeNode right = null;

	    public TreeNode(int val) {
	        this.val = val;
	    }
	}
	public static ArrayList<Integer> PrintFromTopToBottom(TreeNode root) {
		ArrayList<Integer> result = new ArrayList<Integer>();
		if (root == null)
		{
			return result;
		}
		LinkedBlockingQueue<TreeNode> queue = new LinkedBlockingQueue<TreeNode>();
		queue.add(root);
		while (queue.size() > 0)
		{
			if (queue.peek().left != null)
			{
				queue.add(queue.peek().left);
			}
			if (queue.peek().right != null)
			{
				queue.add(queue.peek().right);
			}
			result.add(queue.poll().val);
		}
		return result;
    }
}
