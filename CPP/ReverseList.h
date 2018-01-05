#ifndef REVERSELIST_H_
#define REVERSELIST_H_

/*
 * 题目：定义一个函数，输入一个链表的头结点，反转该链表并输出反转后链表的头结点。
 */
#include <stdio.h>

struct ListNode {
	int m_nValue;
	ListNode* m_pNext;
	ListNode(int value) : m_nValue(value), m_pNext(0) {}
};

ListNode* ReverseList(ListNode* pHead) {
	if (pHead == 0 || pHead->m_pNext == 0) {
		return pHead;
	}
	ListNode* pre = 0;
	ListNode* cur = pHead;
	ListNode* next = pHead->m_pNext;
	while (cur != 0) {
		cur->m_pNext = pre;
		pre = cur;
		cur = next;
		if (next != 0) {
			next = next->m_pNext;
		}
	}
	return pre;
}

ListNode *GetList() {
	ListNode *n1 = new ListNode(1);
	ListNode *n2 = new ListNode(2);
	ListNode *n3 = new ListNode(3);
	ListNode *n4 = new ListNode(4);
	ListNode *n5 = new ListNode(5);

	n1->m_pNext = n2;
	n2->m_pNext = n3;
	n3->m_pNext = n4;
	n4->m_pNext = n5;

	return n1;
}

void ReverseListTest() {
	ListNode* head = GetList();
	head = ReverseList(head);
	while (head) {
		printf("%d\t", head->m_nValue);
		head = head->m_pNext;
	}
}


#endif /* REVERSELIST_H_ */
