package linkedlist;
/*
 * 输入一个链表，输出该链表中倒数第k个结点。
 */
public class linkedlist02 {
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
	public static ListNode FindKthToTail(ListNode head, int k) {
		if (head == null || k <= 0)
		{
			return null;
		}
		int i = 0;
		ListNode first = head;
		ListNode last = head;
		while (head != null && i < k)
		{
			last = head;
			head = head.next;
			i++;
		}
		if (i < k)
		{
			return null;
		}
		while (last.next != null)
		{
			last = last.next;
			first = first.next;
		}
		return first;
    }
}
