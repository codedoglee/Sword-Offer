package string;
/*
 * ������ʽƥ��
 * ��ʵ��һ����������ƥ�����'.'��'*'��������ʽ��ģʽ�е��ַ�'.'��ʾ����һ���ַ�����'*'��ʾ��ǰ����ַ����Գ�������Σ�����0�Σ���
 * �ڱ����У�ƥ����ָ�ַ����������ַ�ƥ������ģʽ�����磬�ַ���"aaa"��ģʽ"a.a"��"ab*ac*a"ƥ�䣬������"aa.a"��"ab*a"����ƥ��
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
