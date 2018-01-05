#ifndef SYMMETRICTREE_H_
#define SYMMETRICTREE_H_

/*
 * 对称的二叉树
 * 题目：请实现一个函数，用来判断一棵二叉树是不是对称形状。
 * 方法：定义一种新的遍历方法，先遍历右子结点，再遍历左子结点。
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
