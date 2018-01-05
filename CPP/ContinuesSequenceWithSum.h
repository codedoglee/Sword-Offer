#ifndef CONTINUESSEQUENCEWITHSUM_H_
#define CONTINUESSEQUENCEWITHSUM_H_

/*
 * ��Ŀ������һ��������s����ӡ�����к�Ϊs���������������У����ٺ�������������
 */
#include <stdio.h>

void PrintSequence(int small, int big) {
	for (int i = small; i <= big; ++i) {
		printf("%d\t", i);
	}
	printf("\n");
}

void ContinuesSequenceWithSum(int sum) {
	if (sum <= 2) {
		return;
	}
	int small = 1;
	int big = 2;
	int currSum = 3;
	while (small < (1+sum)/2) {
		if (currSum == sum) {
			PrintSequence(small, big);
			currSum -= small;
			++small;
		}
		else if (currSum < sum) {
			++big;
			currSum += big;
		}
		else {
			currSum -= small;
			++small;
		}
	}
}

void ContinuesSequenceWithSumTest() {
	ContinuesSequenceWithSum(45);
}


#endif /* CONTINUESSEQUENCEWITHSUM_H_ */
