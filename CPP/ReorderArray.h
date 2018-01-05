#ifndef REORDERARRAY_H_
#define REORDERARRAY_H_

/*
 * ��Ŀ������һ���������飬ʵ��һ�����������������������ֵ�˳��
 * ʹ����������λ�������ǰ�벿�֣�����ż��λ������ĺ�벿�֡�
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
