package linkedlist;
/*
 * ɾ���������ظ��Ľ��
 * ��һ������������У������ظ��Ľ�㣬��ɾ�����������ظ��Ľ�㣬�ظ��Ľ�㲻��������������ͷָ�롣
 * ���磬����1->2->3->3->4->4->5 �����Ϊ 1->2->5
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
