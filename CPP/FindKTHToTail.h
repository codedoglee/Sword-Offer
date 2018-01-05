#ifndef FINDKTHTOTAIL_H_
#define FINDKTHTOTAIL_H_

/*
 * ��Ŀ������һ����������������е�����k����㡣
 * Ϊ�˷��ϴ�����˵�ϰ�ߣ���1��ʼ�������������β����ǵ�����1����㡣
 * ����һ��������6����㣬��ͷ��㿪ʼ���ǵ�ֵ������1��2��3��4��5��6���������ĵ��������������ֵΪ4�Ľ�㡣
 */
#include <stdio.h>

struct ListNode {
	int m_nValue;
	ListNode* m_pNext;
	ListNode(int value) : m_nValue(value), m_pNext(0) {}
};

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

ListNode* FindKTHToTail(ListNode* pHead, int k) {
	if (pHead == 0 || k <= 0) {
		return 0;
	}
	ListNode* left = pHead;
	ListNode* right = pHead;
	for (int i = 0; i < k-1; ++i) {
		if (right->m_pNext != 0) {
			right = right->m_pNext;
		}
		else {
			return 0;
		}
	}
	while (right->m_pNext != 0) {
		left = left->m_pNext;
		right = right->m_pNext;
	}
	return right;
}

void FindKTHToTailTest() {
	ListNode* head = GetList();
	printf("%d\n", FindKTHToTail(head, 5)->m_nValue);
}


#endif /* FINDKTHTOTAIL_H_ */
