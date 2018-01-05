package linkedlist;

import java.util.LinkedList;

/*
 * 约瑟夫环问题
 * 0,1,...,n-1这n个数字排成一个圆圈，从数字0开始每次从这个圆圈里删除第m个数字。求出这个圆圈里剩下的最后一个数字。
 * 递推公式：f(n, m) = 0  					(n = 1)
 *          f(n, m) = [f(n-1, m) + m] % n   (n > 1)
 */
public class linkedlist07 {
	public static void main(String[] args)
	{
		System.out.println(LastRemaining3(5, 3));
	}
	public static int LastRemaining(int n, int m)
	{
		if (n <= 0 || m <= 0)
		{
			return -1;
		}
        LinkedList<Integer> circle = new LinkedList<Integer>();
        for (int i = 0; i < n; ++i)
        {
        	circle.add(i);
        }
        int iter = 0;
        while (circle.size() > 1)
        {
        	for (int i = 1; i < m; ++i)
        	{
        		++iter;
        		if (iter == circle.size())
        		{
        			iter = 0;
        		}
        	}
        	circle.remove(iter);
        	if (iter == circle.size())
        	{
        		iter = 0;
        	}
        }
        return circle.get(iter);
    }
	public static int LastRemaining2(int n, int m)
	{
		if (n <= 0 || m <= 0)
		{
			return -1;
		}
        if (n == 1)
        {
        	return 0;
        }
        return (LastRemaining2(n-1, m) + m) % n;
    }
	public static int LastRemaining3(int n, int m)
	{
		if (n <= 0 || m <= 0)
		{
			return -1;
		}
        int remain = 0;
        for (int i = 2; i <= n; ++i)
        {
        	remain = (remain + m) % i;
        }
        return remain;
    }
}
