package tree;

import java.util.Stack;

/*
 * ����һ�ö��������������ö���������ת����һ�������˫������Ҫ���ܴ����κ��µĽ�㣬ֻ�ܵ������н��ָ���ָ��
 */
public class tree07 {
	public static void main(String[] args)
	{
		TreeNode root = new TreeNode(10);
		TreeNode node1 = new TreeNode(6);
		TreeNode node2 = new TreeNode(15);
		TreeNode node3 = new TreeNode(3);
		TreeNode node4 = new TreeNode(8);
		TreeNode node5 = new TreeNode(12);
		TreeNode node6 = new TreeNode(17);
		TreeNode node7 = new TreeNode(1);
		TreeNode node8 = new TreeNode(9);
		
		root.left = node1;
		root.right = node2;
		node1.left = node3;
		node1.right = node4;
		node2.left = node5;
		node2.right = node6;
		node3.left = node7;
		node4.right = node8;
		
		TreeNode head = Convert(root);
		while (head != null)
		{
			System.out.println(head.val);
			head = head.right;
		}
	}
	public static class TreeNode {
	    int val = 0;
	    TreeNode left = null;
	    TreeNode right = null;

	    public TreeNode(int val) {
	        this.val = val;
	    }
	}
	//�ǵݹ��
	public static TreeNode Convert(TreeNode root)
	{
		if(root == null)
		{
            return null;
		}
        if(root.left == null && root.right == null)
        {
            return root;
        }
        Stack<TreeNode> stack = new Stack<TreeNode>();
        TreeNode node = root;
        TreeNode pre = null;
        TreeNode head = null;
        //���ڵ�һ���ҵ���С�Ľ��
        boolean isfirst = true;
        while (node != null || !stack.isEmpty())
        {
        	if (node != null)
        	{
        		stack.push(node);
            	node = node.left;
        	}
        	else
            {
            	node = stack.pop();
            	if (isfirst)
            	{
            		head = node;
            		pre = head;
            		isfirst = false;
            	}
            	else
            	{
            		node.left = pre;
            		pre.right = node;
            		pre = node;
            	}
            	node = node.right;
            }
        }
        return head;
	}
	
	//�ݹ��
	public static TreeNode Convert2(TreeNode root)
	{
		if(root == null)
		{
            return null;
		}
        if(root.left == null && root.right == null)
        {
            return root;
        }
        // 1.�������������˫��������������ͷ�ڵ�
        TreeNode left = Convert2(root.left);
        TreeNode node = left;
        // 2.��λ��������˫�������һ���ڵ�
        while(node != null && node.right != null)
        {
        	node = node.right;
        }
        // 3.�������������Ϊ�յĻ�������ǰroot׷�ӵ�����������
        if(left != null)
        {
            node.right = root;
            root.left = node;
        }
        // 4.�������������˫��������������ͷ�ڵ�
        TreeNode right = Convert2(root.right);
        // 5.�������������Ϊ�յĻ�����������׷�ӵ�root�ڵ�֮��
        if(right != null)
        {
            right.left = root;
            root.right = right;
        }
        //һֱ������С�Ľ�㣬Ϊleft��root
        return left != null ? left : root;
	}
}
