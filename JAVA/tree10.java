package tree;
/*
 * 二叉树的下一个结点
 * 给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。
 */
public class tree10 {
	public static void main(String[] args)
	{
		
	}
	public class TreeLinkNode {
	    int val;
	    TreeLinkNode left = null;
	    TreeLinkNode right = null;
	    TreeLinkNode parent = null;

	    TreeLinkNode(int val) {
	        this.val = val;
	    }
	}
	public TreeLinkNode GetNext(TreeLinkNode pNode)
    {
        if (pNode == null)
        {
        	return null;
        }
        if (pNode.right != null)
        {
        	TreeLinkNode tNode = pNode.right;
        	while (tNode.left != null)
        	{
        		tNode = tNode.left;
        	}
        	return tNode;
        }
        else
        {
        	if (pNode.parent != null && pNode == pNode.parent.left)
        	{
        		return pNode.parent;
        	}
        	else if (pNode.parent == null)
        	{
        		return null;
        	}
        	else
        	{
        		TreeLinkNode tNode = pNode.parent;
        		while (tNode.parent != null && tNode == tNode.parent.right)
        		{
        			tNode = tNode.parent;
        		}
        		return tNode.parent;
        	}
        }
    }
}
