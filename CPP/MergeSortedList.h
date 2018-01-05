#ifndef MERGESORTEDLIST_H_
#define MERGESORTEDLIST_H_

/*
 * 题目：输入两个递增排序的链表
 */
#include <stdio.h>

struct ListNode {
	int m_nValue;
	ListNode* m_pNext;
	ListNode(int value) : m_nValue(value), m_pNext(0) {}
};

ListNode* MergeSortedList(ListNode* pHead1, ListNode* pHead2) {
	if (pHead1 == 0) {
		return pHead2;
	}
	if (pHead2 == 0) {
		return pHead1;
	}
	ListNode* pHead = 0;
	if (pHead1->m_nValue <= pHead2->m_nValue) {
		pHead = pHead1;
		pHead->m_pNext = MergeSortedList(pHead1->m_pNext, pHead2);
	}
	else {
		pHead = pHead2;
		pHead->m_pNext = MergeSortedList(pHead1, pHead2->m_pNext);
	}
	return pHead;
}

ListNode* MergeSortedListIter(ListNode* pHead1, ListNode* pHead2) {
	if (pHead1 == 0) {
		return pHead2;
	}
	if (pHead2 == 0) {
		return pHead1;
	}
	ListNode* pHead = 0;
	ListNode* p1 = 0;
	ListNode* p2 = 0;
	if (pHead1->m_nValue <= pHead2->m_nValue) {
		pHead = pHead1;
		p1 = pHead1->m_pNext;
		p2 = pHead2;
	}
	else {
		pHead = pHead2;
		p1 = pHead1;
		p2 = pHead2->m_pNext;
	}
	ListNode* pNode = pHead;
	while (p1 && p2) {
		if (p1->m_nValue <= p2->m_nValue) {
			pNode->m_pNext = p1;
			p1 = p1->m_pNext;
		}
		else {
			pNode->m_pNext = p2;
			p2 = p2->m_pNext;
		}
		pNode = pNode->m_pNext;
	}
	if (p1) {
		pNode->m_pNext = p1;
	}
	else if (p2) {
		pNode->m_pNext = p2;
	}
	else {
		pNode->m_pNext = 0;
	}
	return pHead;
}

void MergeSortedListTest() {
	ListNode* n1 = new ListNode(1);
	ListNode* n2 = new ListNode(2);
	ListNode* n3 = new ListNode(3);
	ListNode* n4 = new ListNode(4);
	ListNode* n5 = new ListNode(4);
	ListNode* n6 = new ListNode(5);
	ListNode* n7 = new ListNode(6);
	ListNode* n8 = new ListNode(7);
	ListNode* n9 = new ListNode(8);

	n1->m_pNext = n3;
	n3->m_pNext = n4;
	n4->m_pNext = n5;
	n5->m_pNext = n8;

	n2->m_pNext = n6;
	n6->m_pNext = n7;
	n7->m_pNext = n9;

	//ListNode* head = MergeSortedList(n1, n2);
	ListNode* head = MergeSortedListIter(n1, n2);

	while (head) {
		printf("%d\t", head->m_nValue);
		head = head->m_pNext;
	}
}


#endif /* MERGESORTEDLIST_H_ */
