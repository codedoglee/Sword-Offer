#ifndef ADDTWOBIGNUMBER_H_
#define ADDTWOBIGNUMBER_H_

/*
 * 题目：两个大数（正整数）相加
 * 负数可以考虑[0]位置存储符号位，决定num1和num2的正负
 */
#include <stdio.h>
#include <cstring>
#include <stdlib.h>
#include <time.h>

void PrintNumber(char* number) {
	int len = strlen(number);
	bool begin = false;
	for (int i = 0; i < len; ++i) {
		if (number[i] != '0') {
			begin = true;
		}
		if (begin) {
			printf("%c", number[i]);
		}
	}
	printf("\n");
}

void AddTwoBigNumber(char* number1, char* number2, unsigned int length, char* result) {
	if (number1 == 0 || number2 == 0 || result == 0 || strlen(number1) != length ||
	    strlen(number2) != length || strlen(result) <= length) {
		return;
	}
	int rLength = strlen(result);
	int takeOver = 0;
	for (int i = length - 1; i >= 0; --i) {
		int num1 = number1[i] - '0';
		int num2 = number2[i] - '0';
		int nSum = num1 + num2 + takeOver;
		if (nSum >= 10) {
			takeOver = 1;
			nSum -= 10;
			result[rLength - length + i] = '0' + nSum;
		}
		else if (nSum < 0) {
			takeOver = -1;
			nSum += 10;
			result[rLength - length + i] = '0' + nSum;
		}
		else {
			takeOver = 0;
			result[rLength - length + i] = '0' + nSum;
		}
	}
	if (takeOver == 1) {
		result[rLength - length - 1] = '1';
	}
}

void AddTwoBigNumberTest() {
	char *number1 = new char[21];
	char *number2 = new char[21];
	memset(number1, '0', 20);
	memset(number2, '0', 20);
	number1[20] = '\0';
	number2[20] = '\0';

	char *sum = new char[22];
	memset(sum, '0', 21);
	sum[21] = '\0';

	srand((unsigned long)time(NULL));
	for (int i = 0; i < 20; ++i) {
		number1[i] = '0' + (rand() % 10);
		number2[i] = '0' + (rand() % 10);
	}
	PrintNumber(number1);
	PrintNumber(number2);
	AddTwoBigNumber(number1, number2, 20, sum);
	PrintNumber(sum);
	delete [] number1;
	delete [] number2;
	delete [] sum;
}


#endif /* ADDTWOBIGNUMBER_H_ */
