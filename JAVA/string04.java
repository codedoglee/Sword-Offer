package string;
/*
 * �����������һ����λָ�����ѭ�����ƣ�ROL���������и��򵥵����񣬾������ַ���ģ�����ָ�����������
 * ����һ���������ַ�����S���������ѭ������Kλ���������������磬�ַ�����S=��abcXYZdef��,Ҫ�����ѭ������3λ��Ľ��������XYZdefabc����
 */
public class string04 {
	public static void main(String[] args)
	{
		
	}
	public String LeftRotateString(String str, int n)
	{
        if (str == null || str.length() == 0 || str.length() == 1)
        {
        	return str;
        }
        int sublen = n % str.length();
        String front = str.substring(0, sublen);
        String back = str.substring(sublen, str.length());
        return back + front;
    }
}
