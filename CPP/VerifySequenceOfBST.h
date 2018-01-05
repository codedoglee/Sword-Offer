#ifndef VERIFYSEQUENCEOFBST_H_
#define VERIFYSEQUENCEOFBST_H_

/**
 * 题目：输入一个整数数组，判断该数组是不是某二叉搜索树的后续遍历的结果。
 * 如果是则返回true，否则返回false。假设输入的数组的任意两个数字都互不相同。
 */
#include <stdio.h>

bool VerifySequenceofBST(int* sequence, int nLength) {
	if (sequence == 0 || nLength <= 0) {
		return false;
	}

	// 根节点值
	int rootValue = sequence[nLength-1];

	// 在二叉搜索树中左子树的结点小于根节点
	int i = 0;
	for (; i < nLength; ++i) {
		if (sequence[i] > rootValue) {
			break;
		}
	}

	// 在二叉搜索树中右子树的结点大于根节点
	int j = i;
	for (; j < nLength-1; ++j) {
		if (sequence[i] <= rootValue) {
			return false;
		}
	}

	// 判断左子树是不是二叉搜索树
	bool left = false;
	if (i > 0) {
		left = VerifySequenceofBST(sequence, i);
	}

	// 判断右子树是不是二叉搜索树
	bool right = false;
	if (i < nLength-1) {
		right = VerifySequenceofBST(sequence + i, nLength-1-i);
	}

	return (left && right);
}


#endif /* VERIFYSEQUENCEOFBST_H_ */
