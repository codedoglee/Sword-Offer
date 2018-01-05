#ifndef PRINTTREEFROMTOPTOBOTTOM_H_
#define PRINTTREEFROMTOPTOBOTTOM_H_

#include <stdio.h>
#include <deque>

struct BinaryTreeNode {
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
	BinaryTreeNode(int value) : m_nValue(value), m_pLeft(0), m_pRight(0) {}
};

void PrintTreeFromTopToBottom(BinaryTreeNode* root) {
	if (root == 0) {
		return;
	}
	std::deque<BinaryTreeNode*> dq;
	dq.push_back(root);
	while (!dq.empty()) {
		printf("%d\t", dq.front()->m_nValue);
		if (dq.front()->m_pLeft) {
			dq.push_back(dq.front()->m_pLeft);
		}
		if (dq.front()->m_pRight) {
			dq.push_back(dq.front()->m_pRight);
		}
		dq.pop_front();
	}
}

BinaryTreeNode *GetTree() {
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

void PrintTreeFromTopToBottomTest() {
	BinaryTreeNode* root = GetTree();
	PrintTreeFromTopToBottom(root);
}


#endif /* PRINTTREEFROMTOPTOBOTTOM_H_ */
