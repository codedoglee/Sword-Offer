package array;
/*
 * HZż������Щרҵ������������Щ�Ǽ����רҵ��ͬѧ����������鿪����,���ַ�����:�ڹ��ϵ�һάģʽʶ����,
 * ������Ҫ��������������������,������ȫΪ������ʱ��,����ܺý��������,��������а�������,�Ƿ�Ӧ�ð���ĳ������,
 * �������Աߵ��������ֲ����أ�����:{6,-3,-2,7,-15,1,2,2},����������������Ϊ8(�ӵ�0����ʼ,����3��Ϊֹ)����᲻�ᱻ������ס��
 */
public class array07 {
	public static void main(String[] args)
	{
		
	}
	public int FindGreatestSumOfSubArray(int[] array)
	{
        if (array == null || array.length == 0)
        {
        	return 0;
        }
        int current = array[0];
        int maxsum = array[0];
        for (int i = 1; i < array.length; ++i)
        {
        	current += array[i];
        	if (current > maxsum)
        	{
        		maxsum = current;
        	}
        	if (current < 0)
        	{
        		current = 0;
        	}
        }
        return maxsum;
    }
}
