package other;
/*
 * 我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
 * 解题思路：归结为用1和2相加得到n有几种排序方法。
 */
public class other04 {
	public static void main(String[] args)
	{

	}
	public int RectCover(int target) {
		if (target <= 0)
		{
			return 0;
		}
		if (target == 1)
		{
			return 1;
		}
		if (target == 2)
		{
			return 2;
		}
		int F1 = 1;
		int F2 = 2;
		for (int i = 3; i <= target; ++i)
		{
			F2 = F2 + F1;
			F1 = F2 - F1;
		}
		return F2;
    }
}
