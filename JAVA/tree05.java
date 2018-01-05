package tree;
/*
 * ����һ���������飬�жϸ������ǲ���ĳ�����������ĺ�������Ľ��������������Yes,�������No���������������������������ֶ�������ͬ��
 * ˼·�������������ĺ�����������һ������Ǹ��ڵ㣬�ȱ�������������ֵ��С�ڸ��ڵ㣬���������������ֵ�����ڸ��ڵ㡣
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