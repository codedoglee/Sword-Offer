#ifndef REVERSEWORDINSENTENCE_H_
#define REVERSEWORDINSENTENCE_H_

/*
 * 题目1：输入一个英文句子，翻转句子中单词顺序，但单词内字符的顺序不变。
 * 题目2：字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。请定义一个函数实现字符串左旋转操作的功能。
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

	//翻转整个句子
	ReverseSequence(pStart, pEnd);
	//翻转句子中的每个单词
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
