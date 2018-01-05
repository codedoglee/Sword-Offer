package other;
/*
 * 一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
 * 动态规划，记录中间结果
 */
import java.util.Arrays;

public class other03 {
	public static void main(String[] args)
	{
		System.out.println(JumpFloorII(4));
	}
	public static int JumpFloorII(int target) {
		if (target <= 0)
		{
			return 0;
		}
        int[] result = new int[target];
        Arrays.fill(result, 0);
        result[0] = 1;
        for (int i = 1; i < target; ++i)
        {
        	for (int j = 0; j < i; ++j)
        	{
        		result[i] += result[j];
        	}
        	++result[i];
        }
        return result[target-1];
    }
}
