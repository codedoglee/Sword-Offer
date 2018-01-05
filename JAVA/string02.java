package string;

import java.util.ArrayList;
import java.util.Arrays;

/*
 * ����һ���ַ���,���ֵ����ӡ�����ַ������ַ����������С����������ַ���abc,���ӡ�����ַ�a,b,c
 * �������г����������ַ���abc,acb,bac,bca,cab��cba�� ����밴��ĸ˳������� 
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
