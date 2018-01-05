#ifndef ENTRYNODEINLOOPLIST_H_
#define ENTRYNODEINLOOPLIST_H_

/*
 * 链表中环的入口结点
 * 题目：一个链表中包含环，如何找出环的入口结点？
 */
#include<stdio.h>

struct ListNode {
	int m_nValue;
	ListNode* m_pNext;
	ListNode(int value) : m_nValue(value), m_pNext(0) {}
};

ListNode* EntryNodeInLoopList(ListNode* pHead) {
	if (pHead == 0 || pHead->m_pNext == 0) {
		return 0;
	}
	ListNode* slow = pHead;
	ListNode* fast = pHead;
	while (fast != 0 && fast->m_pNext != 0) {
		slow = slow->m_pNext;
		fast = fast->m_pNext->m_pNext;
		if (slow == fast) {
			break;
		}
	}
	if (slow != fast) {
		return 0;
	}
	ListNode* pNode = pHead;
	while (pNode != slow) {
		pNode = pNode->m_pNext;
		slow = slow->m_pNext;
	}
	return pNode;
}

ListNode* GetLoopList() {
	ListNode *n1 = new ListNode(1);
	ListNode *n2 = new ListNode(2);
	ListNode *n3 = new ListNode(3);
	ListNode *n4 = new ListNode(4);
	ListNode *n5 = new ListNode(5);

	n1->m_pNext = n2;
	n2->m_pNext = n3;
	n3->m_pNext = n4;
	n4->m_pNext = n5;
	n5->m_pNext = n3;

	return n1;
}

void EntryNodeInLoopListTest() {
	ListNode* head = GetLoopList();
	//head->m_pNext = head;
	printf("%d\n", EntryNodeInLoopList(head)->m_nValue);
}


#endif /* ENTRYNODEINLOOPLIST_H_ */
