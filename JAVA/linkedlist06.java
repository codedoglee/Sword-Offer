package linkedlist;

import java.util.Stack;

/*
 * 输入两个链表，找出它们的第一个公共结点
 */
public class linkedlist06 {
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
	public ListNode FindFirstCommonNode(ListNode pHead1, ListNode pHead2)
	{
		 if (pHead1 == null || pHead2 == null)
		 {
			return null; 
		 }
		 Stack<ListNode> stack1 = new Stack<ListNode>();
		 Stack<ListNode> stack2 = new Stack<ListNode>();
		 while (pHead1 != null)
		 {
			 stack1.push(pHead1);
			 pHead1 = pHead1.next;
		 }
		 while (pHead2 != null)
		 {
			 stack2.push(pHead2);
			 pHead2 = pHead2.next;
		 }
		 ListNode same = null;
		 while (!stack1.isEmpty() && !stack2.isEmpty())
		 {
			 if (stack1.peek() != stack2.peek())
			 {
				 break;
			 }
			 else
			 {
				 same = stack1.peek();
				 stack1.pop();
				 stack2.pop();
			 }
		}
		return same;
    }
}
