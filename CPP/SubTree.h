#ifndef SUBTREE_H_
#define SUBTREE_H_

/*
 * 题目：输入两颗二叉树A和B，判断B是不是A的子结构。
 */
#include <stdio.h>

struct BinaryTreeNode {
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
	BinaryTreeNode(int value) : m_nValue(value), m_pLeft(0), m_pRight(0) {}
};

bool DoSubTree(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2) {
	if (pRoot2 == 0) {
		return true;
	}
	if (pRoot1 == 0) {
		return false;
	}
	if (pRoot1->m_nValue != pRoot2->m_nValue) {
		return false;
	}
	return DoSubTree(pRoot1->m_pLeft, pRoot2->m_pLeft) && DoSubTree(pRoot1->m_pRight, pRoot2->m_pRight);
}

bool HasSubTree(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2) {
	bool result = false;
	if (pRoot1 != 0 && pRoot2 != 0) {
		if (pRoot1->m_nValue == pRoot2->m_nValue) {
			result = HasSubTree(pRoot1, pRoot2);
		}
		if (!result) {
			result = HasSubTree(pRoot1->m_pLeft, pRoot2);
		}
		if (!result) {
			result = HasSubTree(pRoot1->m_pRight, pRoot2);
		}
	}
	return result;
}


#endif /* SUBTREE_H_ */
