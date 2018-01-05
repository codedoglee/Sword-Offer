package linkedlist;
/*
 * 删除链表中重复的结点
 * 在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。
 * 例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
 */
public class linkedlist10 {
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
	public ListNode deleteDuplication(ListNode pHead)
    {
		if (pHead == null || pHead.next == null)
		{
			return pHead;
		}
		ListNode current = pHead.next;
		if (pHead.val == current.val)
		{
			while (current.next != null && current.val == current.next.val)
			{
				current = current.next;
			}
			return deleteDuplication(current.next);
		}
		else
		{
			pHead.next = deleteDuplication(current);
			return pHead;
		}
    }
}
