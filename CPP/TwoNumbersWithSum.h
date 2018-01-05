#ifndef TWONUMBERSWITHSUM_H_
#define TWONUMBERSWITHSUM_H_

/*
 * ��Ŀ������һ����������������һ������s���������в�����������ʹ�����ǵĺ�������s��
 * ����ж�����ֵĺ͵���s���������һ�Լ��ɡ�
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
