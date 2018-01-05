#ifndef CONVERTBINARYSEARCHTREE_H_
#define CONVERTBINARYSEARCHTREE_H_

/*
 * ��Ŀ������һ�Ŷ��������������ö���������ת����һ�������˫������
 * Ҫ���ܴ����κ��µĽ�㣬ֻ�ܵ��������ܽ��ָ���ָ��
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
	BinaryTreeNode* leftTail = ConvertCore(pRoot->m_pLeft); //������β
	BinaryTreeNode* leftHead = (leftTail == 0 ? 0 : leftTail->m_pRight); //������ͷ
	BinaryTreeNode* rightTail = ConvertCore(pRoot->m_pRight); //������β
	BinaryTreeNode* rightHead = (rightTail == 0 ? 0 : rightTail->m_pRight); //������ͷ
	if (leftTail != 0 && rightTail != 0) {
		leftTail->m_pRight = pRoot;
		pRoot->m_pLeft = leftTail;
		rightHead->m_pLeft = pRoot;
		pRoot->m_pRight = rightHead;
		rightTail->m_pRight = leftHead;	//��������β����rightָ��ָ����������ͷ
		return rightTail; //����������β�����ҿ���ͨ����rightָ���ҵ���������֮��������ͷ
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
		pRoot->m_pRight = pRoot; //ֻ��һ����㣬��rightָ��ָ���Լ�
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
