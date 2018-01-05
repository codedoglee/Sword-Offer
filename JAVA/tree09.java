package tree;

/*
 * 输入一棵二叉树，判断该二叉树是否是平衡二叉树。
 */
public class tree09 {
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
	};
	public class Depth {
		int depth = 0;
		public Depth(int dep)
		{
			depth = dep;
		}
	};
	public boolean IsBalanced(TreeNode root)
	{
		Depth dep = new Depth(0);
        return IsBalanced(root, dep);
    }
	public boolean IsBalanced(TreeNode root, Depth dep)
	{
		if (root == null)
        {
			dep.depth = 0;
        	return true;
        }
		Depth left = new Depth(0);
		Depth right = new Depth(0);
        if (IsBalanced(root.left, left) && IsBalanced(root.right, right))
        {
        	int diff = left.depth - right.depth;
        	if (diff <= 1 && diff >= -1)
        	{
        		dep.depth = 1 + (left.depth > right.depth ? left.depth : right.depth);
        		return true;
        	}
        }
        return false;
	}
}
