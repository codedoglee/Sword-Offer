package array;

import java.util.ArrayDeque;
import java.util.ArrayList;

/*
 * 滑动窗口的最大值
 * 给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。
 * 例如，如果输入数组{2,3,4,2,6,2,5,1}及滑动窗口的大小3，那么一共存在6个滑动窗口，他们的最大值分别为{4,4,6,6,6,5}；
 * 针对数组{2,3,4,2,6,2,5,1}的滑动窗口有以下6个： {[2,3,4],2,6,2,5,1}， {2,[3,4,2],6,2,5,1}， {2,3,[4,2,6],2,5,1}，
 * {2,3,4,[2,6,2],5,1}， {2,3,4,2,[6,2,5],1}， {2,3,4,2,6,[2,5,1]}。
 * 
 * 双段队列实现，队列里面放下标
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
