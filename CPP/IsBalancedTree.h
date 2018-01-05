#ifndef ISBALANCEDTREE_H_
#define ISBALANCEDTREE_H_

/*
 * 题目：输入一颗二叉树的根节点，判断该树是不是平衡二叉树。
 * 如果某二叉树中任意结点的左右子树的深度相差不超过1，那么它就是一颗平衡二叉树。
 */
#include <stdio.h>
#include "BinaryTreeDepth.h"

bool IsBalancedTree(BinaryTreeNode* pRoot, int* depth) {
	if (pRoot == 0) {
		*depth = 0;
		return true;
	}
	int left = 0;
	int right = 0;
	bool leftBalanced = IsBalancedTree(pRoot->m_pLeft, &left);
	bool rightBalanced = IsBalancedTree(pRoot->m_pRight, &right);
	if (leftBalanced && rightBalanced) {
		int diff = left - right;
		if (diff <= 1 && diff >= -1) {
			*depth = 1 + (left > right ? left : right);
			return true;
		}
	}
	return false;
}

bool IsBalancedTree(BinaryTreeNode* pRoot) {
	int depth = 0;
	return IsBalancedTree(pRoot, &depth);
}

void IsBalancedTreeTest() {
	BinaryTreeNode* root = GetTree();
	printf("%d\n", IsBalancedTree(root));
}


#endif /* ISBALANCEDTREE_H_ */
