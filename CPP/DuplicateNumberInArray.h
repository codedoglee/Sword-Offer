#ifndef DUPLICATENUMBERINARRAY_H_
#define DUPLICATENUMBERINARRAY_H_

/*
 * 数组中重复的数字
 * 题目：在一个人长度为n的数组里的所有数字都在0到n-1的范围内。数组中某些数字是重复的，
 * 但不知道有几个数字重复了，也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。
 */
#include <stdio.h>

bool DuplicateNumber(int* data, int length, int* duplicate) {
	if (data == 0 || length <= 0) {
		return false;
	}
	//检验数据是否符合要求
	for (int i = 0; i < length; ++i) {
		if (data[i] < 0 || data[i] >= length) {
			return false;
		}
	}
	for (int i = 0; i < length; ++i) {
		while (data[i] != i) {
			if (data[i] == data[data[i]]) {
				*duplicate = data[i];
				return true;
			}
			int temp = data[i];
			data[i] = data[data[i]];
			data[data[i]] = temp;
		}
	}
	return false;
}


#endif /* DUPLICATENUMBERINARRAY_H_ */
