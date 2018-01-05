#ifndef DELETENODEINLIST_H_
#define DELETENODEINLIST_H_

/*
 * ��Ŀ���������������ͷָ���һ�����ָ�룬����һ��������O(1)ʱ��ɾ���ý�㡣
 */
#include <stdio.h>

struct ListNode {
	int m_nValue;
	ListNode* m_pNext;
	ListNode(int value) : m_nValue(value), m_pNext(0) {}
};

void DleteNode(ListNode** pHead, ListNode* pToDelete) {
	if (pHead == 0 || *pHead == 0 || pToDelete == 0) {
		return;
	}
	if (pToDelete->m_pNext != 0) {
		ListNode* pNext = pToDelete->m_pNext;
		pToDelete->m_nValue = pNext->m_nValue;
		pToDelete->m_pNext = pNext->m_pNext;

		delete pNext;
		pNext = 0;
	}
	else if (*pHead == pToDelete) {
		delete pToDelete;
		pToDelete = 0;
		*pHead = 0;
	}
	else {
		ListNode* pre = *pHead;
		while (pre->m_pNext != pToDelete) {
			pre = pre->m_pNext;
		}
		pre->m_pNext = pToDelete->m_pNext;
		delete pToDelete;
		pToDelete = 0;
	}
}


#endif /* DELETENODEINLIST_H_ */
