package other;
/*
 * һֻ����һ�ο�������1��̨�ף�Ҳ��������2��������Ҳ��������n���������������һ��n����̨���ܹ��ж�����������
 * ��̬�滮����¼�м���
 */
import java.util.Arrays;

public class other03 {
	public static void main(String[] args)
	{
		System.out.println(JumpFloorII(4));
	}
	public static int JumpFloorII(int target) {
		if (target <= 0)
		{
			return 0;
		}
        int[] result = new int[target];
        Arrays.fill(result, 0);
        result[0] = 1;
        for (int i = 1; i < target; ++i)
        {
        	for (int j = 0; j < i; ++j)
        	{
        		result[i] += result[j];
        	}
        	++result[i];
        }
        return result[target-1];
    }
}
