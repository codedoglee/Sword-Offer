package string;
/*
 * 表示数值的字符串
 * 请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。例如，字符串"+100","5e2","-123","3.1416"和"-1E-16"都表示数值。 
 * 但是"12e","1a3.14","1.2.3","+-5"和"12e+4.3"都不是。
 */
public class string09 {
	public static void main(String[] args)
	{
		String s = "01.2e1";
		System.out.println(isNumeric(s.toCharArray()));
	}
	public static boolean isNumeric(char[] str)
	{
        if (str == null || str.length == 0)
        {
        	return false;
        }
        int i = 0;
        if (str[i] == '+' || str[i] == '-')
        {
        	i++;
        }
        if (i == str.length)
        {
        	return false;
        }
        while (i < str.length && str[i] >= '0' && str[i] <= '9')
        {
        	++i;
        }
        if (i < str.length)
        {
        	if (str[i] == '.')
        	{
        		++i;
        		while (i < str.length && str[i] >= '0' && str[i] <= '9')
                {
                	++i;
                }
        		if (i < str.length && (str[i] == 'e' || str[i] == 'E'))
        		{
        			return isExponential(str, i+1);
        		}
        		if (i < str.length && str[i] == '.')
        		{
        			return false;
        		}
        	}
        	else if (str[i] == 'e' || str[i] == 'E')
        	{
        		return isExponential(str, i+1);
        	}
        	else
        	{
        		return false;
        	}
        }
        return true;
    }
	public static boolean isExponential(char[] str, int i)
	{
		if (i == str.length)
		{
			return false;
		}
		if (str[i] == '+' || str[i] == '-')
		{
			++i;
		}
		if (i == str.length)
		{
			return false;
		}
		while (i < str.length && str[i] >= '0' && str[i] <= '9')
        {
        	++i;
        }
		if (i == str.length)
		{
			return true;
		}
		return false;
	}
}
