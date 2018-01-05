#ifndef NEXTNODEINBINARYTREE_H_
#define NEXTNODEINBINARYTREE_H_

/*
 * 二叉树的下一个结点
 * 题目：给定一棵二叉树和其中的一个结点，如何找出中序遍历顺序的下一个结点？
 */
#include <stdio.h>

struct BinaryTreeNode {
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
	BinaryTreeNode* m_pParent;
	BinaryTreeNode(int value) : m_nValue(value), m_pLeft(0), m_pRight(0), m_pParent(0) {}
};

BinaryTreeNode* GetNextNode(BinaryTreeNode* pNode) {
	if (pNode == 0) {
		return 0;
	}
	BinaryTreeNode* pNext = 0;
	if (pNode->m_pRight != 0) {
		BinaryTreeNode* pRight = pNode->m_pRight;
		while (pRight->m_pLeft != 0) {
			pRight = pRight->m_pLeft;
		}
		pNext = pRight;
	}
	else if (pNode->m_pParent != 0) {
		BinaryTreeNode* pCurrent = pNode;
		BinaryTreeNode* pParent = pNode->m_pParent;
		while (pParent != 0 && pCurrent == pParent->m_pRight) {
			pCurrent = pParent;
			pParent = pParent->m_pParent;
		}
		pNext = pParent;
	}
	return pNext;
}


#endif /* NEXTNODEINBINARYTREE_H_ */
