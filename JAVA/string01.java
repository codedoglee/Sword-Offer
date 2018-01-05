package string;
/*
 * 请实现一个函数，将一个字符串中的空格替换成“%20”。
 * 例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
 */
public class string01 {
	public static void main(String[] args)
	{
		StringBuffer str = new StringBuffer();
		str.append("   ");
		System.out.println(replaceSpace(str));
	}
	
	public static String replaceSpace(StringBuffer str) {
    	if (str == null || str.length() == 0)
    	{
    		return "";
    	}
		String result = "";
		int length = str.length();
    	for (int i = 0; i < length; ++i)
    	{
    		int index = str.indexOf(" ");
    		if (index == -1)
    		{
    			result += str;
    			break;
    		}
    		else
    		{
    			result += str.substring(0, index);
    			result += "%20";
    			i += index;
    			str.delete(0, index+1);
    		}
    	}
    	return result;
    }
}
