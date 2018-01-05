#ifndef REVERSEWORDINSENTENCE_H_
#define REVERSEWORDINSENTENCE_H_

/*
 * ��Ŀ1������һ��Ӣ�ľ��ӣ���ת�����е���˳�򣬵��������ַ���˳�򲻱䡣
 * ��Ŀ2���ַ���������ת�����ǰ��ַ���ǰ������ɸ��ַ�ת�Ƶ��ַ�����β�����붨��һ������ʵ���ַ�������ת�����Ĺ��ܡ�
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ReverseSequence(char* sequence, int start, int end) {
	if (sequence == 0 || start < 0 || start >= end) {
		return;
	}
	int i = start;
	int j = end;
	while (i <= j) {
		char c = sequence[i];
		sequence[i] = sequence[j];
		sequence[j] = c;
		++i;
		--j;
	}
}

void ReverseSequence(char* start, char* end) {
	if (start == 0 || end == 0) {
		return;
	}
	while (start < end) {
		char c = *start;
		*start = *end;
		*end = c;
		++start;
		--end;
	}
}

char* ReverseSentence(char* pData) {
	if (pData == 0) {
		return 0;
	}
	char* pStart = pData;
	char* pEnd = pData;
	while (*pEnd != '\0') {
		++pEnd;
	}
	--pEnd;

	//��ת��������
	ReverseSequence(pStart, pEnd);
	//��ת�����е�ÿ������
	pStart = pEnd = pData;
	while (*pStart != '\0') {
		while (*pEnd != ' ' && *pEnd != '\0') {
			++pEnd;
		}
		--pEnd;
		ReverseSequence(pStart, pEnd);
		++pEnd;
		if (*pEnd == '\0') {
			break;
		}
		else {
			++pEnd;
			pStart = pEnd;
		}
	}
	return pData;
}

char* LeftRotateString(char* pStr, int n) {
	if (pStr == 0 || n < 0) {
		return pStr;
	}
	char* pEnd = pStr;
	while (*pEnd != '\0') {
		++pEnd;
	}
	int nLength = static_cast<int>(strlen(pStr));
	if (nLength < n) {
		return pStr;
	}
	char* firstBegin = pStr;
	char* firstEnd = pStr + n -1;
	char* secondBegin = pStr + n;
	char* secondEnd = pStr + nLength - 1;
	ReverseSequence(firstBegin, firstEnd);
	ReverseSequence(secondBegin, secondEnd);
	ReverseSequence(firstBegin, secondEnd);
	return pStr;
}

void ReverseSentenceTest() {
	char str[] = "I am a student.";
	printf("%s\n", ReverseSentence(str));
}

void LeftRotateStringTest() {
	char str[] = "abcdefg";
	printf("%s\n", LeftRotateString(str, 2));
}


#endif /* REVERSEWORDINSENTENCE_H_ */
