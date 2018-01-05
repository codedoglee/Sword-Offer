package tree;
/*
 * 输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。
 * 思路：二叉搜索树的后序遍历，最后一个结点是根节点，先遍历其左子树，值均小于根节点，后遍历其右子树，值均大于根节点。
 */
public class tree05 {
	public static void main(String[] args)
	{
		int[] a = {2,5,7,6,10,20,15,9};
		System.out.println(VerifySquenceOfBST(a));
	}
	public static boolean VerifySquenceOfBST(int[] sequence)
	{
        if (sequence == null || sequence.length == 0)
        {
        	return false;
        }
        int length = sequence.length;
        int root = sequence[length-1];
        int index = 0;
        while (index < length-1)
        {
        	if (index == length-1)
        	{
        		return true;
        	}
        	if (sequence[index] < root)
        	{
        		++index;
        		continue;
        	}
        	else
        	{
        		break;
        	}
        }
        for (int i = index; i < length-1; ++i)
        {
        	if (sequence[i] < root)
        	{
        		return false;
        	}
        }
        int[] left = new int[index];
    	int[] right = new int[length-1-index];
    	for (int i = 0; i < index; ++i)
    	{
    		left[i] = sequence[i];
    	}
    	for (int i = index; i < length-1; ++i)
    	{
    		right[i-index] = sequence[i];
    	}
    	if (left.length > 0)
    	{
    		if (right.length > 0)
    		{
    			return VerifySquenceOfBST(left) && VerifySquenceOfBST(right);
    		}
    		else
    		{
    			return VerifySquenceOfBST(left);
    		}
    	}
    	else
    	{
    		if (right.length > 0)
    		{
    			return VerifySquenceOfBST(right);
    		}
    		else
    		{
    			return true;
    		}
    	}
    }
}