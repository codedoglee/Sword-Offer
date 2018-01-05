#ifndef ADDWITHOUTPLUS_H_
#define ADDWITHOUTPLUS_H_

/*
 * ��Ŀ��дһ������������������֮�ͣ�Ҫ���ں������ڲ���ʹ��+��-��*��/�������㡣
 */
#include <stdio.h>

int Add(int num1, int num2) {
	int sum, carry;
	do {
		sum = num1 ^ num2;
		carry = (num1 & num2) << 1;

		num1 = sum;
		num2 = carry;
	}
	while (num2 != 0);
	return sum;
}

void AddTest() {
	int num1 = 10;
	int num2 = 777;
	printf("%d\n", Add(num1, num2));
}


#endif /* ADDWITHOUTPLUS_H_ */
