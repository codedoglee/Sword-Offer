package string;

import java.util.HashMap;
import java.util.LinkedList;

/*
 * ��һ���ַ���(1<=�ַ�������<=10000��ȫ���ɴ�Сд��ĸ���)���ҵ���һ��ֻ����һ�ε��ַ�,����������λ��
 */
public class string03 {
	public static void main(String[] args)
	{
		
	}
	public int FirstNotRepeatingChar(String str)
	{
		if (str == null || str == "")
		{
			return -1;
		}
		HashMap<Character, Integer> index = new HashMap<Character, Integer>();
		LinkedList<Character> charList = new LinkedList<Character>();
		LinkedList<Character> charListHelp = new LinkedList<Character>();
		for (int i = 0; i< str.length(); ++i)
		{
			if (charListHelp.contains(str.charAt(i)))
			{
				continue;
			}
			else
			{
				if (charList.contains(str.charAt(i)))
				{
					charList.remove((Object)str.charAt(i));
					charListHelp.add(str.charAt(i));
					index.remove(str.charAt(i));
				}
				else
				{
					charList.add(str.charAt(i));
					index.put(str.charAt(i), i);
				}
			}
		}
		if (charList.isEmpty())
		{
			return -1;
		}
        return index.get(charList.getFirst());
    }
}
