package tree;

import java.util.concurrent.LinkedBlockingQueue;

/*
 * 输入两棵二叉树A，B，判断B是不是A的子结构。我们约定空树不是任意一个树的子结构。
 */
public class tree02 {
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
	public boolean HasSubtree(TreeNode root1,TreeNode root2) {
        if (root1 == null || root2 == null)
        {
            return false;
        }
        LinkedBlockingQueue<TreeNode> que = new LinkedBlockingQueue<TreeNode>();
        try
        {
            TreeNode temp = root1;
            while (temp != null)
            {
                if (temp.left != null)
                {
                    que.put(temp.left);
                }
                if (temp.right != null)
                {
                    que.put(temp.right);
                }
                if (isSubtree(temp, root2))
                {
                    return true;
                }
                temp = que.poll();
            }
        }
        catch (Exception e)
        {
            e.printStackTrace();
        }
        return false;
    }
    public static boolean isSubtree(TreeNode root1, TreeNode root2)
    {
        if (root2 == null)
        {
            return true;
        }
        if (root1 == null)
        {
            return false;
        }
        if (root1.val != root2.val)
        {
            return false;
        }
        return isSubtree(root1.left, root2.left) && isSubtree(root1.right, root2.right);
    }
}
