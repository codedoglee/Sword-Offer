package other;
/*
 * ì³²¨ÄÇÆõÊıÁĞ
 */
public class other01 {
	public static void main(String[] args)
	{
		System.out.println(fibonacci(40));
	}
	public static int fibonacci(int n) {
		if (n == 0)
		{
			return 0;
		}
		if (n == 1)
		{
			return 1;
		}
		int F1 = 0;
		int F2 = 1;
		for (int i = 2; i <=n; ++i)
		{
			F2 = F1 + F2;
			F1 = F2 - F1;
		}
		return F2;
	}
}
