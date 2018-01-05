package linkedlist;

import java.util.HashSet;

/*
 * 一个链表中包含环，请找出该链表的环的入口结点。
 */
public class linkedlist08 {
	public static void main(String[] args)
	{
		
	}
	public class ListNode {
	    int val;
	    ListNode next = null;

	    ListNode(int val) {
	        this.val = val;
	    }
	}
	public ListNode EntryNodeOfLoop(ListNode pHead)
    {
        HashSet<ListNode> set = new HashSet<ListNode>();
        if (pHead == null)
        {
        	return null;
        }
        while (pHead != null)
        {
        	if (set.contains(pHead))
        	{
        		return pHead;
        	}
        	else
        	{
        		set.add(pHead);
        		pHead = pHead.next;
        	}
        }
        return null;
    }
	public ListNode EntryNodeOfLoop2(ListNode pHead)
    {
        ListNode meetNode = MeetingNode(pHead);
        if (meetNode == null)
        {
        	return null;
        }
        int loopnum = 1;
        ListNode tempNode1 = meetNode.next;
        while (tempNode1 != meetNode)
        {
        	loopnum++;
        	tempNode1 = tempNode1.next;
        }
        tempNode1 = pHead;
        ListNode tempNode2 = pHead;
        for (int i = 0; i < loopnum; ++i)
        {
        	tempNode2 = tempNode2.next;
        }
        while (tempNode1 != tempNode2)
        {
        	tempNode1 = tempNode1.next;
        	tempNode2 = tempNode2.next;
        }
        return tempNode1;
    }
	//用一快一慢两个指针获得环中的一个相遇结点。
	public ListNode MeetingNode(ListNode pHead)
	{
		if (pHead == null)
		{
			return null;
		}
		ListNode slow = pHead.next;
		if (slow == null)
		{
			return null;
		}
		ListNode fast = slow.next;
		while (fast != null && slow != null)
		{
			if (fast == slow)
			{
				return fast;
			}
			else
			{
				slow = slow.next;
				fast = fast.next;
				if (fast != null)
				{
					fast = fast.next;
				}
			}
		}
		return null;
	}
}
