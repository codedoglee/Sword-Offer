package tree;
/*
 * ����������һ�����
 * ����һ�������������е�һ����㣬���ҳ��������˳�����һ����㲢�ҷ��ء�ע�⣬���еĽ�㲻�����������ӽ�㣬ͬʱ����ָ�򸸽���ָ�롣
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
