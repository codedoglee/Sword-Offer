package string;
/*
 * ţ���������һ����Ա��Fish��ÿ���糿���ǻ�����һ��Ӣ����־��дЩ�����ڱ����ϡ�ͬ��Cat��Fishд�������ĸ���Ȥ����һ������Fish����������
 * ��ȴ������������˼�����磬��student. a am I������������ʶ������һ�ԭ���Ѿ��ӵ��ʵ�˳��ת�ˣ���ȷ�ľ���Ӧ���ǡ�I am a student.����
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
