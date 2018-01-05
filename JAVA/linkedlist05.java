package linkedlist;
/*
 * 输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点），
 * 返回结果为复制后复杂链表的head。
 */
public class linkedlist05 {
	public static void main(String[] args)
	{
		RandomListNode head = new RandomListNode(1);
		RandomListNode node1 = new RandomListNode(2);
		RandomListNode node2 = new RandomListNode(3);
		head.next = node1;
		node1.next = node2;
		RandomListNode phead = Clone2(head);
		while (phead != null)
		{
			System.out.println(phead.label);
			phead = phead.next;
		}
	}
	public static class RandomListNode {
	    int label;
	    RandomListNode next = null;
	    RandomListNode random = null;

	    RandomListNode(int label) {
	        this.label = label;
	    }
	}
	public static RandomListNode Clone(RandomListNode pHead)
    {
		if (pHead == null)
		{
			return null;
		}
		CloneNode(pHead);
		ConnectRandomNode(pHead);
		return ReconnectNode(pHead);
    }
	public static RandomListNode Clone2(RandomListNode pHead)
    {
		if (pHead == null)
		{
			return null;
		}
		RandomListNode pCloneHead = new RandomListNode(pHead.label);
		RandomListNode pCloneNode = pCloneHead;
		RandomListNode pNode = pHead.next;
		while (pNode != null)
		{
			RandomListNode temp = new RandomListNode(pNode.label);
			pCloneNode.next = temp;
			pCloneNode = pCloneNode.next;
			pNode = pNode.next;
		}
		pNode = pHead;
		pCloneNode = pCloneHead;
		while (pNode != null)
		{
			if (pNode.random != null)
			{
				RandomListNode temp = pCloneHead;
				while (temp != null)
				{
					if (temp.label == pNode.random.label)
					{
						pCloneNode.random = temp;
						break;
					}
					temp = temp.next;
				}
			}
			pNode = pNode.next;
			pCloneNode = pCloneNode.next;
		}
		return pCloneHead;
    }
	public static void CloneNode(RandomListNode pHead)
	{
		while (pHead != null)
		{
			RandomListNode pNode = new RandomListNode(pHead.label);
			pNode.next = pHead.next;
			pHead.next = pNode;
			pHead = pNode.next;
		}
	}
	public static void ConnectRandomNode(RandomListNode pHead)
	{
		while (pHead != null)
		{
			RandomListNode pNode = pHead.next;
			if (pHead.random != null)
			{
				 pNode.random = pHead.random.next;
			}
			pHead = pNode.next;
		}
	}
	public static RandomListNode ReconnectNode (RandomListNode pHead)
	{
		RandomListNode pCloneHead = pHead.next;
		RandomListNode pNode = pCloneHead;
		while (pNode.next != null)
		{
			pNode.next = pNode.next.next;
			pNode = pNode.next;
		}
		return pCloneHead;
	}
}
