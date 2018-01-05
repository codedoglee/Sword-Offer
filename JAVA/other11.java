package other;

import java.util.Comparator;
import java.util.PriorityQueue;

/*
 * �������е���λ��
 * ��εõ�һ���������е���λ����������������ж�����������ֵ����ô��λ������������ֵ����֮��λ���м����ֵ��
 * ������������ж���ż������ֵ����ô��λ������������ֵ����֮���м���������ƽ��ֵ��
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
	// 11��Ĭ�ϵĳ�ʼ����
	public static PriorityQueue<Integer> maxHeap = new PriorityQueue<Integer>(11, new Comparator<Integer>() 
			{
				@Override
				public int compare(Integer o1, Integer o2) {
					return o2.compareTo(o1);
				}
			});
	public static void Insert(Integer num)
	{
		// �������ǰcountΪż����Ӧ�ò�����С��
    	if ((count & 1) == 0)
    	{
    		// �����ѵĶ��׽��бȽ�
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
    	// �������ǰcountΪ������Ӧ�ò�������
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
