package other;
/*
 * ������1���ֵĴ�������1��n������1���ֵĴ�����
 */
public class other07 {
	public static void main(String[] args)
	{
		
	}
	public int NumberOf1Between1AndN_Solution(int n)
	{
		if (n <= 0)
		{
			return 0;
		}
		int result = 0;
	    for (int i = 1; i <= n; ++i)
	    {
	    	int j = i;
	    	while (j != 0)
	    	{
	    		if (j % 10 == 1)
	    		{
	    			++result;
	    		}
	    		j = j / 10;
	    	}
	    }
	    return result;
    }
}
