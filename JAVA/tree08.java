package tree;
/*
 * ����һ�ö����������������ȡ��Ӹ���㵽Ҷ������ξ����Ľ�㣨������Ҷ��㣩�γ�����һ��·�����·���ĳ���Ϊ������ȡ�
 */
public class tree08 {
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
	public int TreeDepth(TreeNode pRoot)
    {
		if (pRoot == null)
		{
			return 0;
		}
		return Math.max(1 + TreeDepth(pRoot.left), 1 + TreeDepth(pRoot.right));
    }
}
