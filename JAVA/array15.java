package array;

import java.util.ArrayDeque;
import java.util.ArrayList;

/*
 * �������ڵ����ֵ
 * ����һ������ͻ������ڵĴ�С���ҳ����л�����������ֵ�����ֵ��
 * ���磬�����������{2,3,4,2,6,2,5,1}���������ڵĴ�С3����ôһ������6���������ڣ����ǵ����ֵ�ֱ�Ϊ{4,4,6,6,6,5}��
 * �������{2,3,4,2,6,2,5,1}�Ļ�������������6���� {[2,3,4],2,6,2,5,1}�� {2,[3,4,2],6,2,5,1}�� {2,3,[4,2,6],2,5,1}��
 * {2,3,4,[2,6,2],5,1}�� {2,3,4,2,[6,2,5],1}�� {2,3,4,2,6,[2,5,1]}��
 * 
 * ˫�ζ���ʵ�֣�����������±�
 */
public class array15 {
	public static void main(String[] args)
	{
		int[] a = {2,3,4,2,6,2,5,1};
		System.out.println(maxInWindows(a, 1));
	}
	public static ArrayList<Integer> maxInWindows(int[] num, int size)
    {
		ArrayList<Integer> result = new ArrayList<Integer>();
        if (num == null || num.length == 0 || size > num.length || size <= 0)
        {
        	return result;
        }
        ArrayDeque<Integer> deque = new ArrayDeque<Integer>();
        int i = 0; 
        int j = 1;
        deque.offerLast(0);
        for (; j < size; ++j)
        {
        	if (num[j] < num[deque.getLast()])
        	{
        		deque.offerLast(j);
        	}
        	else if (num[j] == num[deque.getLast()])
        	{
        		deque.pollLast();
        		deque.offerLast(j);
        	}
        	else
        	{
        		deque.clear();
        		deque.offerLast(j);
        	}
        }
        result.add(num[deque.getFirst()]);
        while (j < num.length)
        {
        	if (deque.getFirst() == i)
        	{
        		deque.removeFirst();
        	}
        	++i;
        	if (!deque.isEmpty() && num[j] < num[deque.getLast()])
        	{
        		deque.offerLast(j);
        	}
        	else if (!deque.isEmpty() && num[j] == num[deque.getLast()])
        	{
        		deque.pollLast();
        		deque.offerLast(j);
        	}
        	else
        	{
        		while (!deque.isEmpty() && num[j] >= num[deque.getLast()])
        		{
        			deque.pollLast();
        		}
        		deque.offerLast(j);
        	}
        	++j;
        	result.add(num[deque.getFirst()]);
        }
        return result;
    }
}
