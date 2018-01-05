#ifndef SYMMETRICTREE_H_
#define SYMMETRICTREE_H_

/*
 * �ԳƵĶ�����
 * ��Ŀ����ʵ��һ�������������ж�һ�ö������ǲ��ǶԳ���״��
 * ����������һ���µı����������ȱ������ӽ�㣬�ٱ������ӽ�㡣
 */
#include <stdio.h>

struct BinaryTreeNode {
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
	BinaryTreeNode(int value) : m_nValue(value), m_pLeft(0), m_pRight(0) {}
};

bool IsSymmetricTree(BinaryTreeNode* pNode1, BinaryTreeNode* pNode2) {
	if (pNode1 == 0 && pNode2 == 0) {
		return true;
	}
	if (pNode1 == 0 || pNode2 == 0) {
		return false;
	}
	if (pNode1->m_nValue != pNode2->m_nValue) {
		return false;
	}
	return IsSymmetricTree(pNode1->m_pLeft, pNode2->m_pRight) && IsSymmetricTree(pNode1->m_pRight, pNode2->m_pLeft);
}

bool IsSymmetricTree(BinaryTreeNode* pRoot) {
	return IsSymmetricTree(pRoot, pRoot);
}


#endif /* SYMMETRICTREE_H_ */
