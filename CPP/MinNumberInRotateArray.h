#ifndef MINNUMBERINROTATEARRAY_H_
#define MINNUMBERINROTATEARRAY_H_

/*
 * 题目：把一个数组最开始的若干个元素搬到数组末尾，我们称之为数组的旋转。
 * 输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。
 * 例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。
 */
#include <stdio.h>
#include <stdexcept>

int MinInOrder(int* numbers, int start, int end) {
	int result = numbers[start];
	for (int i = start; i <= end; ++i) {
		if (numbers[i] < result) {
			result = numbers[i];
		}
	}
	return result;
}

int MinNumberInRotateArray(int* numbers, int length) {
	if (numbers == 0 || length <= 0) {
		std::runtime_error err("Invalid parameters!");
		throw err;
	}
	if (numbers[0] < numbers[length-1]) {
		return numbers[0];
	}
	int left = 0;
	int right = length - 1;
	int middle = 0;
	while (true) {
		if (right - left == 1) {
			return numbers[right];
		}
		middle = (left + right) / 2;
		if (numbers[left] == numbers[right] && numbers[middle] == numbers[right]) {
			return MinInOrder(numbers, left, right);
		}
		if (numbers[middle] >= numbers[left]) {
			left = middle;
		}
		else {
			right = middle;
		}
	}
	return numbers[middle];
}

void MinNumberInRotateArrayTest() {
	int A[] = {3,4,5,1,2};
	int B[] = {1,2,3,4,5};
	int C[] = {1,0,1,1,1};
	int D[] = {1,1,1,0,1};
	printf("%d\n", MinNumberInRotateArray(A, 5));
	printf("%d\n", MinNumberInRotateArray(B, 5));
	printf("%d\n", MinNumberInRotateArray(C, 5));
	printf("%d\n", MinNumberInRotateArray(D, 5));
}


#endif /* MINNUMBERINROTATEARRAY_H_ */
