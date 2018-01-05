#ifndef SORTARRAYFORMINNUMBER_H_
#define SORTARRAYFORMINNUMBER_H_

/*
 * 题目：把数组排成最小的数
 * 输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出来的所有数字中最小的一个。
 * 例如输入数组{3,32,321}，则打印出这3个数能排成的最小数字321323。
 */
#include <stdio.h>
#include <string.h>
#include <algorithm>

#define MAXNUMLEN 10

char* g_StrCombine1 = new char[MAXNUMLEN * 2 + 1];
char* g_StrCombine2 = new char[MAXNUMLEN * 2 + 1];

int Compare(const void* strNumber1, const void* strNumber2) {
	strcpy(g_StrCombine1, *(char**)strNumber1);
	strcat(g_StrCombine1, *(char**)strNumber2);

	strcpy(g_StrCombine2, *(char**)strNumber2);
	strcat(g_StrCombine2, *(char**)strNumber1);

	return strcmp(g_StrCombine1, g_StrCombine2);
}

void PrintMinNumber(int* numbers, int length) {
	if (numbers == 0 || length <= 0) {
		return;
	}
	//有亮点
	char** strNumbers = (char**)(new int[length]);
	for (int i = 0; i < length; ++i) {
		strNumbers[i] = new char[MAXNUMLEN + 1];
		memset(strNumbers[i], '\0', MAXNUMLEN + 1);
		sprintf(strNumbers[i], "%d", numbers[i]);
	}
	std::qsort(strNumbers, length, sizeof(char*), Compare);
	for (int i = 0; i < length; ++i) {
		printf("%s",strNumbers[i]);
	}
	for (int i = 0; i < length; ++i) {
		delete [] strNumbers[i];
	}
	delete [] strNumbers;
}

void PrintMinNumberTest() {
	int A[] = {3, 32, 321};
	PrintMinNumber(A, 3);
}


#endif /* SORTARRAYFORMINNUMBER_H_ */
