package other;

import java.util.Comparator;
import java.util.PriorityQueue;

/*
 * 数据流中的中位数
 * 如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。
 * 如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。
 */
public class other11 {
	public static void main(String[] args)
	{
		Insert(5);
		Insert(2);
		Insert(3);
		Insert(4);
		Insert(1);
		Insert(6);
		Insert(7);
		Insert(0);
		Insert(8);
	}
	static int count = 0;
	public static PriorityQueue<Integer> minHeap = new PriorityQueue<Integer>();
	// 11是默认的初始容量
	public static PriorityQueue<Integer> maxHeap = new PriorityQueue<Integer>(11, new Comparator<Integer>() 
			{
				@Override
				public int compare(Integer o1, Integer o2) {
					return o2.compareTo(o1);
				}
			});
	public static void Insert(Integer num)
	{
		// 插入操作前count为偶数，应该插入最小堆
    	if ((count & 1) == 0)
    	{
    		// 和最大堆的堆首进行比较
    		if (maxHeap.size() > 0 && maxHeap.peek() > num )
    		{
    			maxHeap.add(num);
    			minHeap.add(maxHeap.poll());
    		}
    		else
    		{
    			minHeap.add(num);
    		}
    	}
    	// 插入操作前count为奇数，应该插入最大堆
    	else
    	{
    		if (minHeap.size() > 0 && minHeap.peek() < num)
    		{
    			minHeap.add(num);
    			maxHeap.add(minHeap.poll());
    		}
    		else
    		{
    			maxHeap.add(num);
    		}
    	}
    	++count;
    }
    public static Double GetMedian()
    {
        if (count == 0)
        {
        	return 0.0;
        }
        else
        {
        	if ((count & 1) == 0)
        	{
        		return (double) (maxHeap.peek() + minHeap.peek()) / 2;
        	}
        	else
        	{
        		return (double) minHeap.peek();
        	}
        }
    }
}
