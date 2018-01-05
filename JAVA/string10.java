package string;
/*
 * �ַ����е�һ�����ظ����ַ�
 * ��ʵ��һ�����������ҳ��ַ����е�һ��ֻ����һ�ε��ַ������磬�����ַ�����ֻ����ǰ�����ַ�"go"ʱ����һ��ֻ����һ�ε��ַ���"g"��
 * ���Ӹ��ַ����ж���ǰ�����ַ���google"ʱ����һ��ֻ����һ�ε��ַ���"l"��
 * PS:�����ǰ�ַ���û�д��ڳ���һ�ε��ַ�������#�ַ���
 */
public class string10 {
	public static void main(String[] args)
	{
		System.out.println();
	}
	//0��ʾδ���֣�-1��ʾ���ֶ��,���ڵ���1��ʾ����һ��(ֵԽС��ʾԽ�����)��
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
