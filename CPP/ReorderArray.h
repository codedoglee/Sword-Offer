#ifndef REORDERARRAY_H_
#define REORDERARRAY_H_

/*
 * 题目：输入一个整数数组，实现一个函数来调整该数组中数字的顺序，
 * 使得所有奇数位于数组的前半部分，所有偶数位于数组的后半部分。
 */
#include <stdio.h>

bool isEven(int n) {
	if (n & 1) {
		return false;
	}
	return true;
}

void ReorderArrayOddEven(int* data, int length) {
	if (data == 0 || length <= 0) {
		return;
	}
	int* left = data;
	int* right = data + length - 1;
	while (left < right) {
		while (left < right && !isEven(*left)) {
			++left;
		}
		while (left < right && isEven(*right)) {
			--right;
		}
		if (left < right) {
			int temp = *left;
			*left = *right;
			*right = temp;
		}
	}
}


#endif /* REORDERARRAY_H_ */
