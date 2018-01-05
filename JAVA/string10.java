package string;
/*
 * 字符流中第一个不重复的字符
 * 请实现一个函数用来找出字符流中第一个只出现一次的字符。例如，当从字符流中只读出前两个字符"go"时，第一个只出现一次的字符是"g"。
 * 当从该字符流中读出前六个字符“google"时，第一个只出现一次的字符是"l"。
 * PS:如果当前字符流没有存在出现一次的字符，返回#字符。
 */
public class string10 {
	public static void main(String[] args)
	{
		System.out.println();
	}
	//0表示未出现，-1表示出现多次,大于等于1表示出现一次(值越小表示越早出现)。
	int[] occurrence = new int[256];
	int index = 1;
    public void Insert(char ch)
    {
        if (occurrence[ch] == 0)
        {
        	occurrence[ch] = index;
        	index++;
        }
        else if (occurrence[ch] >= 1)
        {
        	occurrence[ch] = -1;
        }
    }
    public char FirstAppearingOnce()
    {
    	char ch = '#';
    	int minIndex = Integer.MAX_VALUE;
    	for (int i = 0; i < 256; i++)
    	{
    		if (occurrence[i] >= 1 && occurrence[i] < minIndex)
    		{
    			ch = (char)i;
    			minIndex = occurrence[i];
    		}
    	}
    	return ch;
    }
}
