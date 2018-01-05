#ifndef PRINTLISTREVERSELY_H_
#define PRINTLISTREVERSELY_H_

#include <stdio.h>
#include <stack>

struct ListNode {
	int m_nValue;
	ListNode* m_pNext;
	ListNode(int value) : m_nValue(value), m_pNext(0) {}
};

void PintListReversely_Iteratively (ListNode* pHead) {
	std::stack<ListNode*> st;
	ListNode* pNode = pHead;
	while (pNode != 0) {
		st.push(pNode);
		pNode = pNode->m_pNext;
	}
	while (!st.empty()) {
		printf("%d\t", st.top()->m_nValue);
		st.pop();
	}
}


void PrintListReversely_Recursively(ListNode* pHead) {
	if (pHead == 0) {
		return;
	}
	else {
		PrintListReversely_Recursively(pHead->m_pNext);
		printf("%d\t", pHead->m_nValue);
	}
}

ListNode *GetList() {
	ListNode *n1 = new ListNode(3);
	ListNode *n2 = new ListNode(1);
	ListNode *n3 = new ListNode(5);
	ListNode *n4 = new ListNode(2);
	ListNode *n5 = new ListNode(4);

	n1->m_pNext = n2;
	n2->m_pNext = n3;
	n3->m_pNext = n4;
	n4->m_pNext = n5;

	return n1;
}

void PrintListReverselyTest() {
	ListNode* head = GetList();
	PrintListReversely_Recursively(head);
}


#endif /* PRINTLISTREVERSELY_H_ */
