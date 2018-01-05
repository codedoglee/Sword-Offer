#ifndef FIRSTCOMMONNODEINLIST_H_
#define FIRSTCOMMONNODEINLIST_H_

/*
 * 两个链表的第一个公共结点
 * 题目：输入两个链表，找出他们的第一个公共节点。
 */
#include <stdio.h>

struct ListNode {
	int m_nValue;
	ListNode* m_pNext;
	ListNode(int value) : m_nValue(value), m_pNext(0) {}
};

bool HasLoop(ListNode* pHead) {
	if (pHead == 0 || pHead->m_pNext == 0) {
		return false;
	}
	ListNode* slow = pHead;
	ListNode* fast = pHead;
	while (fast != 0 && fast->m_pNext != 0) {
		slow = slow->m_pNext;
		fast = fast->m_pNext->m_pNext;
		if (slow == fast) {
			return true;
		}
	}
	return false;
}

//环形链表的环入口结点
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

//两个链表无环，找出第一个公共结点
ListNode* FirstCommonNodeNoneLoop(ListNode* pHead1, ListNode* pHead2, ListNode* pEndNode = 0) {
	if (pHead1 == 0 || pHead2 == 0) {
		return 0;
	}
	ListNode* pNode1 = pHead1;
	ListNode* pNode2 = pHead2;
	//链表长度
	int length1 = 0;
	int length2 = 0;
	while (pNode1 != pEndNode) {
		++length1;
		pNode1 = pNode1->m_pNext;
	}
	while (pNode2 != pEndNode) {
		++length2;
		pNode2 = pNode2->m_pNext;
	}
	pNode1 = pHead1;
	pNode2 = pHead2;
	if (length1 > length2) {
		int i = 0;
		while (i < length1 - length2) {
			pNode1 = pNode1->m_pNext;
			++i;
		}
	}
	else if (length1 < length2) {
		int i = 0;
		while (i < length2 - length1) {
			pNode2 = pNode2->m_pNext;
			++i;
		}
	}
	while (pNode1 != pEndNode && pNode2 != pEndNode) {
		if (pNode1 == pNode2) {
			return pNode1;
		}
		pNode1 = pNode1->m_pNext;
		pNode2 = pNode2->m_pNext;
	}
	if (pNode1 != 0 && pNode2 != 0 && pNode1->m_pNext == pNode2->m_pNext) {
		return pNode1->m_pNext;
	}

	return 0;
}

//两个链表有环，找出第一个公共结点
ListNode* FirstCommonNodeLoop(ListNode* pHead1, ListNode* pHead2) {
	ListNode* pEntryNode1 = EntryNodeInLoopList(pHead1);
	ListNode* pEntryNode2 = EntryNodeInLoopList(pHead2);
	ListNode* pNode1 = pEntryNode1;
	if (pEntryNode1 != pEntryNode2) {
		while (pNode1->m_pNext != pEntryNode1) {
			if (pNode1 == pEntryNode2) {
				return pNode1;
			}
			pNode1 = pNode1->m_pNext;
		}
		return 0;
	}
	else {
		return FirstCommonNodeNoneLoop(pHead1, pHead2, pEntryNode1->m_pNext);
	}
}

ListNode* FirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
	if (pHead1 == 0 || pHead2 == 0) {
		return 0;
	}

	bool hasLoop1 = HasLoop(pHead1);
	bool hasLoop2 = HasLoop(pHead2);

	//一个有环，一个无环，肯定不相交
	if ((hasLoop1 && !hasLoop2) || (!hasLoop1 && hasLoop2)) {
		return 0;
	}

	//两个都无环，不相交或为Y形
	if (!hasLoop1 && !hasLoop2) {
		return FirstCommonNodeNoneLoop(pHead1, pHead2);
	}

	//两个都有环
	else if (hasLoop1 && hasLoop2) {
		return FirstCommonNodeLoop(pHead1, pHead2);
	}
	return 0;
}

void FirstCommonNodeTest() {
	ListNode *n1 = new ListNode(1);
	ListNode *n2 = new ListNode(2);
	ListNode *n3 = new ListNode(3);
	ListNode *n4 = new ListNode(4);
	ListNode *n5 = new ListNode(5);
	ListNode *n6 = new ListNode(6);
	ListNode *n7 = new ListNode(7);
	ListNode *n8 = new ListNode(8);
	ListNode *n9 = new ListNode(9);

	n1->m_pNext = n2;
	n2->m_pNext = n3;
	n3->m_pNext = n4;
	n4->m_pNext = n5;
	n5->m_pNext = n6;
	n6->m_pNext = n7;
	n7->m_pNext = n8;

	n8->m_pNext = n4;

	n9->m_pNext = n4;

	printf("%d\n", FirstCommonNode(n1, n9)->m_nValue);
}


#endif /* FIRSTCOMMONNODEINLIST_H_ */
