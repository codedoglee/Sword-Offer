#ifndef FINDPATHINTREE_H_
#define FINDPATHINTREE_H_

/**
 * 题目：输入一颗二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
 * 从数的根节点开始往下一直找到叶结点所经过的结点形成一条路径。
 */
#include <stdio.h>
#include <deque>

struct BinaryTreeNode {
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
	BinaryTreeNode(int value) : m_nValue(value), m_pLeft(0), m_pRight(0) {}
};

void FindPath(BinaryTreeNode* root, std::deque<int>& path, int currentSum, int expectedSum) {
	currentSum += root->m_nValue;
	path.push_back(root->m_nValue);

	bool leaf = (root->m_pLeft == 0 && root->m_pRight == 0);
	if (currentSum == expectedSum && leaf) {
		printf("A path is found: ");
		std::deque<int>::iterator it = path.begin();
		for (; it != path.end(); ++it) {
			printf("%d\t", *it);
		}
		printf("\n");
	}

	if (root->m_pLeft != 0) {
		FindPath(root->m_pLeft, path, currentSum, expectedSum);
	}
	if (root->m_pRight != 0) {
		FindPath(root->m_pRight, path, currentSum, expectedSum);
	}
	path.pop_back();
}

void FindFathInTree(BinaryTreeNode* root, int expectedSum) {
	if (root == 0) {
		return;
	}
	std::deque<int> path;
	int currentSum = 0;
	FindPath(root, path, currentSum, expectedSum);
}

BinaryTreeNode* GetTree() {
	BinaryTreeNode *n1 = new BinaryTreeNode(1);
	BinaryTreeNode *n2 = new BinaryTreeNode(2);
	BinaryTreeNode *n3 = new BinaryTreeNode(3);
	BinaryTreeNode *n4 = new BinaryTreeNode(4);
	BinaryTreeNode *n5 = new BinaryTreeNode(5);
	BinaryTreeNode *n6 = new BinaryTreeNode(6);
	BinaryTreeNode *n7 = new BinaryTreeNode(7);
	BinaryTreeNode *n11 = new BinaryTreeNode(11);

	n1->m_pLeft = n2;
	n1->m_pRight = n3;
	n2->m_pLeft = n4;
	n2->m_pRight = n5;
	n3->m_pRight = n6;
	n3->m_pLeft = n11;
	n5->m_pLeft = n7;

	return n1;
}

void FindFathInTreeTest() {
	BinaryTreeNode* root = GetTree();
	FindFathInTree(root, 15);
}


#endif /* FINDPATHINTREE_H_ */
