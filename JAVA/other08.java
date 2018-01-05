package other;

import java.util.ArrayList;

/*
 * 输出所有和为S的连续正数序列。序列内按照从小至大的顺序，序列间按照开始数字从小到大的顺序
 */
public class other08 {
	public static void main(String[] args)
	{
		System.out.println(FindContinuousSequence(100));
	}
	@SuppressWarnings("unchecked")
	public static ArrayList<ArrayList<Integer>> FindContinuousSequence(int sum)
	{
		ArrayList<ArrayList<Integer>> result = new ArrayList<ArrayList<Integer>>();
		if (sum <= 2)
		{
			return result;
		}
		int start = 1;
		int end = 1;
		int cursum = 1;
		ArrayList<Integer> temp = new ArrayList<Integer>();
		temp.add(1);
		while (end <= sum / 2 + 1)
		{
			
			if (cursum == sum)
			{
				result.add((ArrayList<Integer>) temp.clone());
				++end;
				cursum += end;
				temp.add(end);
			}
			else if (cursum < sum)
			{
				++end;
				cursum += end;
				temp.add(end);
			}
			else
			{
				cursum -=start;
				temp.remove((Object)start);
				++start;
			}
		}
		return result;
    }
}
