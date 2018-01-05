#ifndef MINNUMBERINROTATEARRAY_H_
#define MINNUMBERINROTATEARRAY_H_

/*
 * ��Ŀ����һ�������ʼ�����ɸ�Ԫ�ذᵽ����ĩβ�����ǳ�֮Ϊ�������ת��
 * ����һ����������������һ����ת�������ת�������СԪ�ء�
 * ��������{3,4,5,1,2}Ϊ{1,2,3,4,5}��һ����ת�����������СֵΪ1��
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
