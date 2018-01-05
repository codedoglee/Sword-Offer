package tree;

import java.util.LinkedList;

/*
 * 序列化二叉树
 * 请实现两个函数，分别用来序列化和反序列化二叉树
 */
public class tree14 {
	public static void main(String[] args)
	{
		TreeNode node1 = new TreeNode(1);
		TreeNode node2 = new TreeNode(2);
		TreeNode node3 = new TreeNode(3);
		TreeNode node4 = new TreeNode(4);
		TreeNode node5 = new TreeNode(5);
		TreeNode node6 = new TreeNode(6);
		node1.left = node2;
		node1.right = node3;
		node2.left = node4;
		node3.left = node5;
		node3.right = node6;
		
		System.out.println(Serialize(node1));
	}
	public static class TreeNode {
	    int val = 0;
	    TreeNode left = null;
	    TreeNode right = null;

	    public TreeNode(int val) {
	        this.val = val;
	    }
	}
	public static String Serialize(TreeNode root)
	{
        if (root == null)
        {
        	return "#,";
        }
        String result = String.valueOf(root.val);
        result += ",";
        result += Serialize(root.left);
        result += Serialize(root.right);
        return result;
	}
	public static TreeNode Deserialize(String str)
	{
		if (str == null || str == "")
		{
			return null;
		}
		String[] values = str.split(",");
		LinkedList<String> queue= new LinkedList<String>();
		for(int i = 0; i < values.length; ++i)
        {
            queue.add(values[i]);
        }
		return preOrder(queue);
	}
	public static TreeNode preOrder(LinkedList<String> queue)
	{
		String value = queue.poll();
	    if(value.equals("#"))
	    {
	        return null;
	    }
	    TreeNode head = new TreeNode(Integer.parseInt(value));
	    head.left = preOrder(queue);
	    head.right = preOrder(queue);
	    return head;
	}
}
