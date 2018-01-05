#ifndef UGLYNUMBER_H_
#define UGLYNUMBER_H_

/*
 * ����
 * ��Ŀ����ֻ��������2��3��5������Ϊ������Ugly Number����
 * �󰴴�С�����˳��ĵ�1500��������ϰ���ϰ�1������һ��������
 */
#include <stdio.h>

typedef long long LL;

LL Min(LL n1, LL n2, LL n3) {
	LL res = n1;
	if (n2 < res) {
		res = n2;
	}
	if (n3 < res) {
		res = n3;
	}
	return res;
}

LL GetUglyNumber(int index) {
	if (index <= 0) {
		return -1;
	}
	LL* uglyNumbers = new LL[index];
	uglyNumbers[0] = 1;
	int nextUglyIndex = 1;

	LL* pMultiply2 = uglyNumbers;
	LL* pMultiply3 = uglyNumbers;
	LL* pMultiply5 = uglyNumbers;

	while (nextUglyIndex < index) {
		LL min = Min(*pMultiply2 * 2, *pMultiply3 * 3, *pMultiply5 * 5);
		uglyNumbers[nextUglyIndex] = min;
		while (*pMultiply2 * 2 <= min) {
			++pMultiply2;
		}
		while (*pMultiply3 * 3 <= min) {
			++pMultiply3;
		}
		while (*pMultiply5 * 5 <= min) {
			++pMultiply5;
		}
		++nextUglyIndex;
	}
	LL ugly = uglyNumbers[index - 1];
	delete [] uglyNumbers;
	return ugly;
}

void GetUglyNumberTest() {
	printf("%I64d\n", GetUglyNumber(3000));
}


#endif /* UGLYNUMBER_H_ */
