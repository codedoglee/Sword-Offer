package string;
/*
 * 正则表达式匹配
 * 请实现一个函数用来匹配包括'.'和'*'的正则表达式。模式中的字符'.'表示任意一个字符，而'*'表示它前面的字符可以出现任意次（包含0次）。
 * 在本题中，匹配是指字符串的所有字符匹配整个模式。例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但是与"aa.a"和"ab*a"均不匹配
 */
public class string08 {
	public static void main(String[] args)
	{
		String str = "";
		String pattern = ".*";
		System.out.println(match(str.toCharArray(), pattern.toCharArray()));
	}
	public static boolean match(char[] str, char[] pattern)
    {
        if (str == null || pattern == null)
        {
        	return false;
        }
        return matchCore(str, 0, pattern, 0);
    }
	public static boolean matchCore(char[] str, int i, char[] pattern, int j)
	{
		if (i == str.length && j == pattern.length)
		{
			return true;
		}
		if (j+1 < pattern.length && pattern[j+1] == '*')
		{
			if ((i < str.length && pattern[j] == str[i]) || pattern[j] == '.')
			{
				return matchCore(str, i, pattern, j+2) || matchCore(str, i+1, pattern, j) || matchCore(str, i+1, pattern, j+2); 
			}
			else
			{
				return matchCore(str, i, pattern, j+2);
			}
		}
		if (i < str.length)
		{
			if (j == pattern.length)
			{
				return false;
			}
			if (j < pattern.length && (pattern[j] == str[i] || pattern[j] == '.'))
			{
				return matchCore(str, i+1, pattern, j+1);
			}
		}
		return false;
	}
}
