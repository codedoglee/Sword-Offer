package linkedlist;

import java.util.ArrayList;
import java.util.Stack;

/*
 * ����һ��������β��ͷ��ӡ����ÿ���ڵ��ֵ��
 * ����Ϊ����ı�ͷ
 * ���Ϊ��Ҫ��ӡ�ġ��������ı�ͷ 
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
