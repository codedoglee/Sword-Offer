package string;
/*
 * 将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。
 */
public class string07 {
	public static void main(String[] args)
	{
		
	}
	enum Status {Valid, Invalid};
	static Status stat = Status.Valid;
	public static int StrToInt(String str)
	{
        if (str == null || str.trim().equals("") || str.trim().equals("+") || str.trim().equals("-"))
        {
        	stat = Status.Invalid;
        	return 0;
        }
        int result = 0;
        boolean isPositive = true;
        if (str.charAt(0) == '-')
        {
        	isPositive = false;
        	str = str.substring(1);
        }
        else if (str.charAt(0) == '+')
        {
        	isPositive = true;
        	str = str.substring(1);
        }
        for (int i = 0; i < str.length(); ++i)
        {
        	if (str.charAt(i) < '0' || str.charAt(i) > '9')
        	{
        		stat = Status.Invalid;
            	return 0;
        	}
        	result = result * 10 + str.charAt(i) - '0';
        }
        if (!isPositive)
        {
        	return 0 - result;
        }
        return result;
    }
}
