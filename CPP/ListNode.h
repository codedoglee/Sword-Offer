#ifndef LISTNODE_H_
#define LISTNODE_H_

/*
 * ������Ĳ����ɾ������
 */
#include <stdio.h>

struct ListNode {
	int m_nValue;
	ListNode* m_pNext;
	ListNode(int value) : m_nValue(value), m_pNext(0) {}
};

void AddToTail(ListNode** pHead /* ��Ϊͷ�����ܻ�ı䣬����Ҫ�ö���ָ�� */, int value) {
	ListNode* newNode = new ListNode(value);
	if (*pHead == 0) {
		*pHead = newNode;
	}
	else {
		ListNode* pNode = *pHead;
		while (pNode->m_pNext) {
			pNode = pNode->m_pNext;
		}
		pNode->m_pNext = newNode;
	}
}

void RemoveNode(ListNode** pHead, int value) {
	if (pHead == 0 || *pHead == 0) {
		return;
	}
	ListNode* pNodeToBeDeleted = 0;		// �����ͷ��ڴ�
	if ((*pHead)->m_nValue == value) {
		pNodeToBeDeleted = *pHead;
		*pHead = (*pHead)->m_pNext;
	}
	else {
		ListNode* pNode = *pHead;
		while (pNode->m_pNext != 0 && pNode->m_pNext->m_nValue != value) {
			pNode = pNode->m_pNext;
		}
		// ��Ǵ�ɾ������ǰ�����
		if (pNode->m_pNext != 0 && pNode->m_pNext->m_nValue == value) {
			pNodeToBeDeleted = pNode->m_pNext;
			pNode->m_pNext = pNode->m_pNext->m_pNext;
		}
		if (pNodeToBeDeleted != 0) {
			delete pNodeToBeDeleted;
			pNodeToBeDeleted = 0;
		}
	}
}


#endif /* LISTNODE_H_ */
