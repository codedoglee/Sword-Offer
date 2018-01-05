package tree;

import java.util.ArrayList;

/*
 * ��֮����˳���ӡ������
 * ��ʵ��һ����������֮���δ�ӡ������������һ�а��մ����ҵ�˳���ӡ���ڶ��㰴�մ��������˳���ӡ��
 * �����а��մ����ҵ�˳���ӡ���������Դ����ơ�
 */
public class tree12 {
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
	@SuppressWarnings("unchecked")
	public ArrayList<ArrayList<Integer>> Print(TreeNode pRoot)
	{
		ArrayList<ArrayList<Integer>> result = new ArrayList<ArrayList<Integer>>();
		ArrayList<Integer> row = new ArrayList<Integer>();
		ArrayList<TreeNode> rowNode = new ArrayList<TreeNode>();
		if (pRoot == null)
		{
			return result;
		}
		row.add(pRoot.val);
		rowNode.add(pRoot);
		result.add((ArrayList<Integer>) row.clone());
		int i = 2;
		while (true)
		{
			for (int j = row.size() - 1; j >= 0; --j)
			{
				TreeNode node = rowNode.get(j);
				if (i % 2 == 0)
				{
					if (node.right != null)
					{
						rowNode.add(node.right);
						row.add(node.right.val);
					}
					if (node.left != null)
					{
						rowNode.add(node.left);
						row.add(node.left.val);
					}
					rowNode.remove(j);
					row.remove(j);
				}
				else
				{
					if (node.left != null)
					{
						rowNode.add(node.left);
						row.add(node.left.val);
					}
					if (node.right != null)
					{
						rowNode.add(node.right);
						row.add(node.right.val);
					}
					rowNode.remove(j);
					row.remove(j);
				}
			}
			if (row.isEmpty())
			{
				break;
			}
			result.add((ArrayList<Integer>) row.clone());
			++i;
		}
		return result;
    }
}
