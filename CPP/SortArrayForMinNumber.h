#ifndef SORTARRAYFORMINNUMBER_H_
#define SORTARRAYFORMINNUMBER_H_

/*
 * ��Ŀ���������ų���С����
 * ����һ�����������飬����������������ƴ�������ų�һ��������ӡ��ƴ�ӳ�����������������С��һ����
 * ������������{3,32,321}�����ӡ����3�������ųɵ���С����321323��
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
	//������
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
