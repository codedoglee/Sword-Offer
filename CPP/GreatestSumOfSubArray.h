#ifndef GREATESTSUMOFSUBARRAY_H_
#define GREATESTSUMOFSUBARRAY_H_

/*
 * ��Ŀ����������������
 * ����һ���������飬������������Ҳ�и�����������һ���������Ķ���������һ�������顣
 * ������������ĺ͵����ֵ��Ҫ��ʱ�临�Ӷ�ΪO(n)��
 */
#include <stdio.h>

bool g_bInvalidInput = false;

int GreatestSumOfSubArray(int* numbers, int length) {
	if (numbers == 0 || length <= 0) {
		g_bInvalidInput = true;
		return 0;
	}
	g_bInvalidInput = false;
	int result = 0x80000000;
	int current = 0;
	for (int i = 0; i < length; ++i) {
		current += numbers[i];
		if (current > result) {
			result = current;
		}
		if (current < 0) {
			current = 0;
		}
	}
	return result;
}

void GreatestSumOfSubArrayTest() {
	int A[] = {1,-2,3,10,-4,7,2,-5};
	printf("%d\n", GreatestSumOfSubArray(A, 8));
}


#endif /* GREATESTSUMOFSUBARRAY_H_ */
