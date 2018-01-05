package tree;
/*
 * ���������Ķ�����������任ΪԴ�������ľ���
 * �������ľ����壺Դ������ 
 *   	    8
 *   	   /  \
 *   	  6   10
 *   	 / \  / \
 *   	5  7 9 11
 * ���������
 *   	    8
 *   	   /  \
 *   	  10   6
 *   	 / \  / \
 *   	11 9 7  5
 */
public class tree03 {
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
	public void Mirror(TreeNode root) {
        if (root != null)
        {
            TreeNode temp = root.left;
            root.left = root.right;
            root.right = temp;
            if (root.left != null)
            {
                Mirror(root.left);
            }
            if(root.right != null)
            {
                Mirror(root.right);
            }
        }
    }
}
