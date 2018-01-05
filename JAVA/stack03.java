package stack;

import java.util.Stack;

/*
 * ���������������У���һ�����б�ʾջ��ѹ��˳�����жϵڶ��������Ƿ�Ϊ��ջ�ĵ���˳��
 * ����ѹ��ջ���������־�����ȡ���������1,2,3,4,5��ĳջ��ѹ��˳������4,5,3,2,1�Ǹ�ѹջ���ж�Ӧ��һ���������У�
 * ��4,3,5,1,2�Ͳ������Ǹ�ѹջ���еĵ������С���ע�⣺���������еĳ�������ȵģ�
 */
public class stack03 {
	public static void main(String[] args)
	{
		int[] a = {1};
		int[] b = {2};
		System.out.println(IsPopOrder(a, b));
	}
	public static boolean IsPopOrder(int[] pushA, int[] popA)
	{
		if (pushA == null || popA == null || pushA.length == 0 || popA.length == 0 || pushA.length != popA.length)
		{
			return false;
		}
		Stack<Integer> data = new Stack<Integer>();
		int i = 0;
		int j = 0;
		int length = pushA.length;
		while (j < length)
		{
			//ֻ��ջ��Ԫ�ؽ��бȽ�
			while (data.isEmpty() || data.peek() != popA[j])
			{
				if (i == length)
				{
					break;
				}
				data.push(pushA[i]);
				i++;
			}
			if (data.peek() != popA[j])
			{
				break;
			}
			data.pop();
			j++;
		}
		if (data.isEmpty() && j == length)
		{
			return true;
		}
		return false;
    }
}
