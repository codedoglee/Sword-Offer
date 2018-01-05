package string;
/*
 * 牛客最近来了一个新员工Fish，每天早晨总是会拿着一本英文杂志，写些句子在本子上。同事Cat对Fish写的内容颇感兴趣，有一天他向Fish借来翻看，
 * 但却读不懂它的意思。例如，“student. a am I”。后来才意识到，这家伙原来把句子单词的顺序翻转了，正确的句子应该是“I am a student.”。
 */
public class string05 {
	public static void main(String[] args)
	{
		System.out.println(ReverseSentence(" "));
	}
	public static String ReverseSentence(String str)
	{
		if (str == null || str.trim().equals(""))
		{
			return str;
		}
        String[] buf = str.split(" ");
        String result = "";
        for (int i = buf.length-1; i > 0; --i)
        {
        	result = result + buf[i] + " ";
        }
        result += buf[0];
        return result;
    }
}
