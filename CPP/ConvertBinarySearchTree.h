#ifndef CONVERTBINARYSEARCHTREE_H_
#define CONVERTBINARYSEARCHTREE_H_

/*
 * 题目：输入一颗二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。
 * 要求不能创建任何新的结点，只能调整树汇总结点指针的指向。
 */
#include <stdio.h>

struct BinaryTreeNode {
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
	BinaryTreeNode(int value) : m_nValue(value), m_pLeft(0), m_pRight(0) {}
};

BinaryTreeNode* ConvertCore(BinaryTreeNode* pRoot) {
	if (pRoot == 0) {
		return 0;
	}
	BinaryTreeNode* leftTail = ConvertCore(pRoot->m_pLeft); //左子树尾
	BinaryTreeNode* leftHead = (leftTail == 0 ? 0 : leftTail->m_pRight); //左子树头
	BinaryTreeNode* rightTail = ConvertCore(pRoot->m_pRight); //右子树尾
	BinaryTreeNode* rightHead = (rightTail == 0 ? 0 : rightTail->m_pRight); //右子树头
	if (leftTail != 0 && rightTail != 0) {
		leftTail->m_pRight = pRoot;
		pRoot->m_pLeft = leftTail;
		rightHead->m_pLeft = pRoot;
		pRoot->m_pRight = rightHead;
		rightTail->m_pRight = leftHead;	//将右子树尾结点的right指针指向左子树的头
		return rightTail; //返回右子树尾，并且可以通过其right指针找到整个重连之后的链表的头
	}
	else if (leftTail != 0) {
		leftTail->m_pRight = pRoot;
		pRoot->m_pLeft = leftTail;
		pRoot->m_pRight = leftHead;
		return pRoot;
	}
	else if (rightTail != 0) {
		rightHead->m_pLeft = pRoot;
		pRoot->m_pRight = rightHead;
		rightTail->m_pRight = pRoot;
		return rightTail;
	}
	else {
		pRoot->m_pRight = pRoot; //只有一个结点，其right指针指向自己
		return pRoot;
	}
}

BinaryTreeNode* ConvertBinarySearchTree(BinaryTreeNode* pRoot) {
	if (pRoot == 0) {
		return 0;
	}
	BinaryTreeNode* pTail = ConvertCore(pRoot);
	BinaryTreeNode* pHead = pTail->m_pRight;
	pTail->m_pRight = 0;
	return pHead;
}

BinaryTreeNode* GetBinarySearchTree() {
	BinaryTreeNode *n1 = new BinaryTreeNode(1);
	BinaryTreeNode *n2 = new BinaryTreeNode(2);
	BinaryTreeNode *n3 = new BinaryTreeNode(3);
	BinaryTreeNode *n4 = new BinaryTreeNode(4);
	BinaryTreeNode *n5 = new BinaryTreeNode(5);
	BinaryTreeNode *n6 = new BinaryTreeNode(6);
	BinaryTreeNode *n7 = new BinaryTreeNode(7);

	n4->m_pLeft = n2;
	n4->m_pRight = n6;
	n2->m_pLeft = n1;
	n2->m_pRight = n3;
	n6->m_pLeft = n5;
	n6->m_pRight = n7;

	return n4;
}

void ConvertBinarySearchTreeTest() {
	BinaryTreeNode* root = GetBinarySearchTree();
	root = ConvertBinarySearchTree(root);
	while (root) {
		printf("%d\t", root->m_nValue);
		root = root->m_pRight;
	}
}


#endif /* CONVERTBINARYSEARCHTREE_H_ */
