package other;

import java.util.ArrayList;

/*
 * ������к�ΪS�������������С������ڰ��մ�С�����˳�����м䰴�տ�ʼ���ִ�С�����˳��
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
