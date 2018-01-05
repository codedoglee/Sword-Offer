package string;

import java.util.ArrayList;
import java.util.Arrays;

/*
 * 输入一个字符串,按字典序打印出该字符串中字符的所有排列。例如输入字符串abc,则打印出由字符a,b,c
 * 所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。 结果请按字母顺序输出。 
 */
public class string02 {
	public static void main(String[] args)
	{
		String s = "fhfgskxnd";
		System.out.println(Permutation(s));
	}
	public static ArrayList<String> Permutation(String str)
	{
		ArrayList<String> result = new ArrayList<String>();
		if (str.length() == 0)
		{
			return result;
		}
		result.add(str);
		int len = str.length();
		Permutation(result, len, 0);
		Object[] rr = result.toArray();
		Arrays.sort(rr);
		result.clear();
		for (int i = 0; i < rr.length; ++i)
		{
			result.add(rr[i].toString());
		}
		return result;
    }
	public static void Permutation(ArrayList<String> res, int len, int index)
	{
		if (index < len-1)
		{
			int size = res.size();
			for (int i = 0; i < size; i++)
			{
				String current = res.get(i);
				String first = String.valueOf(current.charAt(index));
				for (int j = index+1; j < current.length(); ++j)
				{
					StringBuilder sb = new StringBuilder(current);
					sb.replace(index, index+1, String.valueOf(current.charAt(j)));
					sb.replace(j, j+1, String.valueOf(first));
					if (!res.contains(sb.toString()))
					{
						res.add(sb.toString());
					}
				}
			}
		}
		else
		{
			return;
		}
		++index;
		Permutation(res, len, index);
	}
}
