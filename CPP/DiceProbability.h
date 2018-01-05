#ifndef DICEPROBABILITY_H_
#define DICEPROBABILITY_H_

/*
 * 题目：把n个骰子扔在地上，所有骰子朝上一面的点数之和为s。
 * 输入n，打印出s的所有可能的值出现的概率。
 * 思路：f(n) = f(n-1) + f(n-2) + f(n-3) + f(n-4) + f(n-5) + f(n-6);
 */
#include <stdio.h>
#include <math.h>

#define DICEVALUE 6

void PrintDiceProbability(int num) {
	if (num <= 0) {
		return;
	}

	int* pHappenTimes[2];
	pHappenTimes[0] = new int[num * DICEVALUE + 1];
	pHappenTimes[1] = new int[num * DICEVALUE + 1];
	for (int i = 0; i < num * DICEVALUE + 1; ++i) {
		pHappenTimes[0][i] = 0;
		pHappenTimes[1][i] = 0;
	}
	int flag = 0; //用于转换数组
	for (int i = 1; i <= DICEVALUE; ++i) {
		pHappenTimes[0][i] = 1;
	}
	for (int k = 2; k <= num; ++k) {
		//k个骰子，点数之和不可能小于k
		for (int i = 1; i < k; ++i) {
			pHappenTimes[1-flag][i] = 0;
		}
		//k个骰子，点数之和在k-6k之间
		for (int i = k; i <= k * DICEVALUE; ++i) {
			pHappenTimes[1-flag][i] = 0;
			for (int j = 1; j < i && j <= DICEVALUE; ++j) {
				pHappenTimes[1-flag][i] += pHappenTimes[flag][i-j];
			}
		}
		flag = 1 - flag;
	}
	double total = pow((double)DICEVALUE, num);
	for (int i = num; i <= DICEVALUE * num; ++i) {
		double probability = (double)pHappenTimes[flag][i] / total;
		printf("%4d:\t%.9f\n", i, probability);
	}
	delete[] pHappenTimes[0];
	delete[] pHappenTimes[1];
}

void PrintDiceProbabilityTest() {
	PrintDiceProbability(10);
}


#endif /* DICEPROBABILITY_H_ */
