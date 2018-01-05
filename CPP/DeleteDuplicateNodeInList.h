#ifndef DELETEDUPLICATENODEINLIST_H_
#define DELETEDUPLICATENODEINLIST_H_

/*
 * ɾ���������ظ��Ľ��
 * ��Ŀ����һ������������У����ɾ���ظ��Ľ�㣿
 */
struct ListNode {
	int m_nValue;
	ListNode* m_pNext;
	ListNode(int value) : m_nValue(value), m_pNext(0) {}
};

void DeleteDuplicateNode(ListNode** pHead) {
	if (pHead == 0 || *pHead== 0 || (*pHead)->m_pNext == 0) {
		return;
	}
	ListNode* pPre = *pHead;
	ListNode* pNode = pPre->m_pNext;
	ListNode* pNext = pNode->m_pNext;
	while (pNode != 0) {
		if (pPre->m_nValue == pNode->m_nValue) {
			delete pNode;
		}
		else {
			pPre->m_pNext = pNode;
			pPre = pNode;
		}
		pNode = pNext;
		if (pNext != 0) {
			pNext = pNext->m_pNext;
		}
	}
	pPre->m_pNext = 0;
}


#endif /* DELETEDUPLICATENODEINLIST_H_ */
