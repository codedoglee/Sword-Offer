package linkedlist;
/*
 * 输入一个链表，反转链表后，输出链表的所有元素。
 */
public class linkedlist03 {
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
	public static ListNode ReverseList(ListNode head)
	{
		if (head == null || head.next == null)
		{
			return head;
		}
		ListNode first = null;
		ListNode second = head;
		ListNode third = second.next;
		while (true)
		{
			second.next = first;
			first = second;
			second = third;
			third = third.next;
			if (third == null)
			{
				second.next = first;
				break;
			}
		}
		return second;
    }
}
