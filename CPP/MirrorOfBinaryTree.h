#ifndef MIRROROFBINARYTREE_H_
#define MIRROROFBINARYTREE_H_

/*
 * ��Ŀ�������һ������������һ�����������ú���������ľ���
 */
#include <stdio.h>

struct BinaryTreeNode {
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
	BinaryTreeNode(int value) : m_nValue(value), m_pLeft(0), m_pRight(0) {}
};

void MirrorOfBinaryTree(BinaryTreeNode* root) {
	if (root == 0) {
		return;
	}
	if (root->m_pLeft == 0 && root->m_pRight == 0) {
		return;
	}
	BinaryTreeNode* pTemp = root->m_pLeft;
	root->m_pLeft = root->m_pRight;
	root->m_pRight = pTemp;
	if (root->m_pLeft != 0) {
		MirrorOfBinaryTree(root->m_pLeft);
	}
	if (root->m_pRight != 0) {
		MirrorOfBinaryTree(root->m_pRight);
	}
}


#endif /* MIRROROFBINARYTREE_H_ */
