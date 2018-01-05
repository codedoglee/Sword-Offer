#ifndef TWONUMBERSAPPEARONCE_H_
#define TWONUMBERSAPPEARONCE_H_

/*
 * ��Ŀ��һ�����������������������֮�⣬���������ֶ����������Ρ�
 * ��д�������ҳ�������ֻ����һ�ε����֡�Ҫ��ʱ�临�Ӷ���O(n)���ռ临�Ӷ���O(1)��
 */
#include "stdio.h"

int FindFirstOneBitIndex(int number) {
	int index = 0;
	while ((number && 1) == 0 && index < (8 * sizeof(int))) {
		++index;
		number  = number >> 1;
	}
	return index;
}

bool IsBitOne(int number, int bitIndex) {
	number = number >> bitIndex;
	return (number & 1);
}

void TwoNumbersAppearOnce(int* data, int length, int* num1, int* num2) {
	if (data == 0 || length <= 1 || num1 == 0 || num2 == 0) {
		return;
	}
	int resultExclusiveOr = 0;
	for (int i = 0; i < length; ++i) {
		resultExclusiveOr ^= data[i];
	}
	int diffBitIndex = FindFirstOneBitIndex(resultExclusiveOr);
	*num1 = *num2 = 0;
	for (int i = 0; i< length; ++i) {
		if (IsBitOne(data[i], diffBitIndex)) {
			*num1 ^= data[i];
		}
		else {
			*num2 ^= data[i];
		}
	}
}


#endif /* TWONUMBERSAPPEARONCE_H_ */
