package tree;

import java.util.Stack;

/*
 * 输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向。
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
	//非递归版
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
        //用于第一次找到最小的结点
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
	
	//递归版
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
        // 1.将左子树构造成双链表，并返回链表头节点
        TreeNode left = Convert2(root.left);
        TreeNode node = left;
        // 2.定位至左子树双链表最后一个节点
        while(node != null && node.right != null)
        {
        	node = node.right;
        }
        // 3.如果左子树链表不为空的话，将当前root追加到左子树链表
        if(left != null)
        {
            node.right = root;
            root.left = node;
        }
        // 4.将右子树构造成双链表，并返回链表头节点
        TreeNode right = Convert2(root.right);
        // 5.如果右子树链表不为空的话，将该链表追加到root节点之后
        if(right != null)
        {
            right.left = root;
            root.right = right;
        }
        //一直返回最小的结点，为left或root
        return left != null ? left : root;
	}
}
