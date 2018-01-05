package linkedlist;
/*
 * ���������������������������������ϳɺ��������Ȼ������Ҫ�ϳɺ���������㵥����������
 */
public class linkedlist04 {
	public static void main(String[] args)
	{
		ListNode list1 = new ListNode(1);
		ListNode node1 = new ListNode(3);
		ListNode node2 = new ListNode(5);
		ListNode list2 = new ListNode(2);
		ListNode node3 = new ListNode(4);
		ListNode node4 = new ListNode(6);
		list1.next = node1;
		node1.next = node2;
		list2.next = node3;
		node3.next = node4;
		ListNode head = Merge(list1, list2);
		while (head != null)
		{
			System.out.printf("%4d", head.val);
			head = head.next;
		}
	}
	public static class ListNode {
	    int val;
	    ListNode next = null;

	    ListNode(int val) {
	        this.val = val;
	    }
	}
	//�ǵݹ�
	public static ListNode Merge(ListNode list1, ListNode list2)
	{
        if (list1 == null)
        {
        	return list2;
        }
        if (list2 == null)
        {
        	return list1;
        }
        ListNode head = null;
        ListNode cur = null;
        ListNode comp1 = null;
        ListNode comp2 = null;
        if (list1.val <= list2.val)
        {
        	head = list1;
        	cur = list1;
        	comp1 = list1.next;
        	comp2 = list2;
        }
        else
        {
        	head = list2;
        	cur = list2;
        	comp1 = list1;
        	comp2 = list2.next;
        }
    	while (true)
    	{
    		if (comp1 == null)
    		{
    			cur.next = comp2;
    			break;
    		}
    		if (comp2 == null)
    		{
    			cur.next = comp1;
    			break;
    		}
    		if (comp1.val <= comp2.val)
    		{
    			cur.next = comp1;
    			cur = cur.next;
    			comp1 = comp1.next;
    		}
    		else
    		{
    			cur.next = comp2;
    			cur = cur.next;
    			comp2 = comp2.next;
    		}
    	}
    	return head;
    }
	//�ݹ�
	public static ListNode Merge2(ListNode list1, ListNode list2)
	{
		if (list1 == null)
        {
        	return list2;
        }
        if (list2 == null)
        {
        	return list1;
        }
        ListNode head = null;
        if (list1.val <= list2.val)
        {
        	head = list1;
        	head.next = Merge2(list1.next, list2);
        }
        else
        {
        	head = list2;
        	head.next = Merge2(list1, list2.next);
        }
        return head;
	}
}
