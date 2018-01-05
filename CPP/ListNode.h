#ifndef LISTNODE_H_
#define LISTNODE_H_

/*
 * 单链表的插入和删除操作
 */
#include <stdio.h>

struct ListNode {
	int m_nValue;
	ListNode* m_pNext;
	ListNode(int value) : m_nValue(value), m_pNext(0) {}
};

void AddToTail(ListNode** pHead /* 因为头结点可能会改变，所以要用二级指针 */, int value) {
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
	ListNode* pNodeToBeDeleted = 0;		// 用于释放内存
	if ((*pHead)->m_nValue == value) {
		pNodeToBeDeleted = *pHead;
		*pHead = (*pHead)->m_pNext;
	}
	else {
		ListNode* pNode = *pHead;
		while (pNode->m_pNext != 0 && pNode->m_pNext->m_nValue != value) {
			pNode = pNode->m_pNext;
		}
		// 标记待删除结点的前驱结点
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
