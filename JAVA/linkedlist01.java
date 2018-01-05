package linkedlist;

import java.util.ArrayList;
import java.util.Stack;

/*
 * 输入一个链表，从尾到头打印链表每个节点的值。
 * 输入为链表的表头
 * 输出为需要打印的“新链表”的表头 
 */
public class linkedlist01 {
	public static void main(String[] args)
	{
		
	}
	public class ListNode {
		int val;
		ListNode next = null;
		ListNode(int val) 
		{
			this.val = val;
		}
	}
	public ArrayList<Integer> printListFromTailToHead(ListNode listNode) {
        Stack<Integer> stk = new Stack<Integer>();
        ArrayList<Integer> result = new ArrayList<Integer>();
        while (listNode != null)
        {
        	stk.push(listNode.val);
        	listNode = listNode.next;
        }
        while (!stk.isEmpty())
        {
        	result.add(stk.pop());
        }
        return result;
    }
}
