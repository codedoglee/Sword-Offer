package array;
/*
 * 一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。
 * 异或运算
 */
public class array12 {
	public static void main(String[] args)
	{

	}
	public void FindNumsAppearOnce(int[] array, int num1[], int num2[])
	{
        if (array == null || array.length < 2)
        {
        	return;
        }
        int length = array.length;
        int resultExclusiveOr = 0;
        for (int i = 0; i < length; ++i)
        {
        	resultExclusiveOr ^= array[i];
        }
        int indexof1 = findFirstBit1(resultExclusiveOr);
        num1[0] = 0;
        num2[0] = 0;
        for (int i = 0; i < length; ++i)
        {
        	if (isBit1(array[i], indexof1))
        	{
        		num1[0] ^= array[i];
        	}
        	else
        	{
        		num2[0] ^= array[i];
        	}
        }
    }
	public int findFirstBit1(int num)
	{
		int indexBit = 0;
		while ((num & 1) == 0 && (indexBit < Integer.SIZE))
		{
			num = num >> 1;
			++indexBit;
		}
		return indexBit;
	}
	public boolean isBit1(int num, int indexBit)
	{
		num = num >> indexBit;
        if ((num & 1) == 1)
        {
        	return true;
        }
        else
        {
        	return false;
        }
	}
}
