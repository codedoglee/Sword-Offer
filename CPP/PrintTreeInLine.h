#ifndef PRINTTREEINLINE_H_
#define PRINTTREEINLINE_H_

/*
 * 把二叉树打印成多行
 * 题目：从上到下按层打印二叉树，同一层的结点按从左到右
 */
#include <stdio.h>
#include <deque>

struct BinaryTreeNode {
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
	BinaryTreeNode(int value) : m_nValue(value), m_pLeft(0), m_pRight(0) {}
};

void PrintTreeInLine(BinaryTreeNode* pRoot) {
	if (pRoot == 0) {
		return;
	}
	std::deque<BinaryTreeNode*> dq;
	dq.push_back(pRoot);
	int nextLevel = 0;
	int toBePrinted = 1;
	while (!dq.empty()) {
		BinaryTreeNode* pNode = dq.front();
		printf("%d\t", pNode->m_nValue);
		if (pNode->m_pLeft != 0) {
			dq.push_back(pNode->m_pLeft);
			++nextLevel;
		}
		if (pNode->m_pRight != 0) {
			dq.push_back(pNode->m_pRight);
			++nextLevel;
		}
		dq.pop_front();
		--toBePrinted;
		if (toBePrinted == 0) {
			printf("\n");
			toBePrinted = nextLevel;
			nextLevel = 0;
		}
	}
}


#endif /* PRINTTREEINLINE_H_ */
