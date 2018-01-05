#ifndef CONTINUESSEQUENCEWITHSUM_H_
#define CONTINUESSEQUENCEWITHSUM_H_

/*
 * 题目：输入一个正整数s，打印出所有和为s的连续正整数序列（至少含有两个数）。
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
