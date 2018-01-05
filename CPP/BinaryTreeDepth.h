#ifndef BINARYTREEDEPTH_H_
#define BINARYTREEDEPTH_H_

/*
 * 题目：输入一棵二叉树的根节点，求该树的深度。
 */
#include <stdio.h>

struct BinaryTreeNode {
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
	BinaryTreeNode(int value) : m_nValue(value), m_pLeft(0), m_pRight(0) {}
};

int GetBinaryTreeDepth(BinaryTreeNode* pRoot) {
	if (pRoot == 0) {
		return 0;
	}
	int left = GetBinaryTreeDepth(pRoot->m_pLeft);
	int right = GetBinaryTreeDepth(pRoot->m_pRight);
	return (left >= right) ? (left + 1) : (right + 1);
}

BinaryTreeNode* GetTree() {
	BinaryTreeNode *n1 = new BinaryTreeNode(1);
	BinaryTreeNode *n2 = new BinaryTreeNode(2);
	BinaryTreeNode *n3 = new BinaryTreeNode(3);
	BinaryTreeNode *n4 = new BinaryTreeNode(4);
	BinaryTreeNode *n5 = new BinaryTreeNode(5);
	BinaryTreeNode *n6 = new BinaryTreeNode(6);
	BinaryTreeNode *n7 = new BinaryTreeNode(7);

	n1->m_pLeft = n2;
	n1->m_pRight = n3;
	n2->m_pLeft = n4;
	n2->m_pRight = n5;
	n3->m_pRight = n6;
	n5->m_pLeft = n7;

	return n1;
}

void GetBinaryTreeDepthTest() {
	BinaryTreeNode* root = GetTree();
	printf("%d\n", GetBinaryTreeDepth(root));
}


#endif /* BINARYTREEDEPTH_H_ */
