#ifndef TWONUMBERSWITHSUM_H_
#define TWONUMBERSWITHSUM_H_

/*
 * 题目：输入一个递增排序的数组和一个数字s，在数组中查找两个数，使得它们的和正好是s。
 * 如果有多对数字的和等于s，输出任意一对即可。
 */
#include <stdio.h>

bool TwoNumbersWithSum(int* data, int length, int sum, int* num1, int* num2) {
	if (data == 0 || length <= 1 || num1 == 0 || num2 == 0) {
		return false;
	}
	int i = 0;
	int j = length-1;
	bool found = false;
	while (i < j) {
		if (data[i] + data[j] == sum) {
			*num1 = data[i];
			*num2 = data[j];
			found = true;
			break;
		}
		else if (data[i] + data[j] < sum) {
			++i;
		}
		else {
			--j;
		}
	}
	return found;
}


#endif /* TWONUMBERSWITHSUM_H_ */
