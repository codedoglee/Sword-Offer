#ifndef COPYCOMPLEXLIST_H_
#define COPYCOMPLEXLIST_H_

/*
 * 题目：请实现函数ComplexListNode* CopyComplexList(ComplexListNode* pHead)，复制一个复杂链表。
 * 在复杂链表中，每个结点除了有一个m_pNext指针指向下一个结点外，还有一个m_pSibling指向链表中的任意结点或者NULL。
 * 此函数除了下面的实现方法之外，还有一种简单但较费空间的做法，使用map。
 */
#include <stdio.h>
#include <map>

struct ComplexListNode {
	int m_nValue;
	ComplexListNode* m_pNext;
	ComplexListNode* m_pSibling;
	ComplexListNode(int value) : m_nValue(value), m_pNext(0), m_pSibling(0) {}
};

void CloneNode(ComplexListNode* pHead) {
	ComplexListNode* pNode = pHead;
	while (pNode != 0) {
		ComplexListNode *pCloneNode = new ComplexListNode(pNode->m_nValue);
		pCloneNode->m_pNext = pNode->m_pNext;
		pNode->m_pNext = pCloneNode;

		pNode = pCloneNode->m_pNext;
	}
}

void ConnectSiblingNode(ComplexListNode* pHead) {
	ComplexListNode* pNode = pHead;
	while (pNode != 0) {
		if (pNode->m_pSibling != 0) {
			pNode->m_pNext->m_pSibling = pNode->m_pSibling->m_pNext;
		}
		pNode = pNode->m_pNext->m_pNext;
	}
}

ComplexListNode* ReconnectNode(ComplexListNode* pHead) {
	ComplexListNode* pNode = pHead;
	ComplexListNode* pCloneHead = 0;
	ComplexListNode* pCloneNode = 0;
	if (pHead == 0) {
		return pCloneHead;
	}
	pCloneHead = pNode->m_pNext;
	pCloneNode = pCloneHead;
	pNode->m_pNext = pCloneNode->m_pNext;
	pNode = pNode->m_pNext;
	while (pNode != 0) {
		pCloneNode->m_pNext = pNode->m_pNext;
		pCloneNode = pCloneNode->m_pNext;
		pNode->m_pNext = pCloneNode->m_pNext;
		pNode = pNode->m_pNext;
	}
	return pCloneHead;
}

ComplexListNode* CopyComplexList(ComplexListNode* pHead) {
	CloneNode(pHead);
	ConnectSiblingNode(pHead);
	return ReconnectNode(pHead);
}

ComplexListNode* CopyComplexListHash(ComplexListNode* pHead) {
	ComplexListNode* pNode = pHead;
	ComplexListNode* pCloneHead = 0;
	ComplexListNode* pCloneNode = 0;
	if (pHead == 0) {
		return pCloneHead;
	}
	pCloneHead = pCloneNode = new ComplexListNode(pNode->m_nValue);
	std::map<ComplexListNode*, ComplexListNode*> mp;
	mp.insert(std::map<ComplexListNode*, ComplexListNode*>::value_type(pNode, pCloneNode));
	pNode = pNode->m_pNext;
	while (pNode != 0) {
		ComplexListNode* pTemp = new ComplexListNode(pNode->m_nValue);
		pCloneNode->m_pNext = pTemp;
		pCloneNode = pCloneNode->m_pNext;
		mp.insert(std::map<ComplexListNode*, ComplexListNode*>::value_type(pNode, pCloneNode));
		pNode = pNode->m_pNext;
	}
	pNode = pHead;
	pCloneNode = pCloneHead;
	std::map<ComplexListNode*, ComplexListNode*>::iterator it = mp.begin();
	while (pNode != 0) {
		if (pNode->m_pSibling != 0) {
			mp[pNode]->m_pSibling = mp[pNode->m_pSibling];
		}
		pNode = pNode->m_pNext;
	}
	return pCloneHead;
}

ComplexListNode *GetComplexList() {
	ComplexListNode *n1 = new ComplexListNode(1);
	ComplexListNode *n2 = new ComplexListNode(2);
	ComplexListNode *n3 = new ComplexListNode(3);
	ComplexListNode *n4 = new ComplexListNode(4);
	ComplexListNode *n5 = new ComplexListNode(5);

	n1->m_pNext = n2;
	n2->m_pNext = n3;
	n3->m_pNext = n4;
	n4->m_pNext = n5;

	n1->m_pSibling = n3;
	n2->m_pSibling = n5;
	n4->m_pSibling = n1;

	return n1;
}

void CopyComplexListTest() {
	ComplexListNode* head = GetComplexList();
	//ComplexListNode* newHead = CopyComplexList(head);
	ComplexListNode* newHead = CopyComplexListHash(head);
	printf("原始链表：");
	while (head) {
		printf("(%d,%d)  ", head->m_nValue, head->m_pSibling == 0 ? 0 : head->m_pSibling->m_nValue);
		head = head->m_pNext;
	}
	printf("\n克隆链表：");
	while (newHead) {
		printf("(%d,%d)  ", newHead->m_nValue, newHead->m_pSibling == 0 ? 0 : newHead->m_pSibling->m_nValue);
		newHead = newHead->m_pNext;
	}
}


#endif /* COPYCOMPLEXLIST_H_ */
