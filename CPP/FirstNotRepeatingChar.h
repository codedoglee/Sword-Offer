#ifndef FIRSTNOTREPEATINGCHAR_H_
#define FIRSTNOTREPEATINGCHAR_H_

/*
 * 第一个只出现一次的字符
 * 题目：在字符串中找出第一个只出现一次的字符。
 * 如输入"abaccdeff"，则输出'b'。
 */
#include <stdio.h>
#include <string.h>

char FirstNotRepeatingChar(char* pStr) {
	if (pStr == 0) {
		return '\0';
	}
	char result = '\0';
	int* hash = new int[256];
	memset(hash, 0, 256*sizeof(int));
	char* pCh = pStr;
	while (*pCh != '\0') {
		++hash[(int)*pCh];
		++pCh;
	}
	pCh = pStr;
	while (*pCh != '\0') {
		if (hash[(int)*pCh] == 1) {
			result = *pCh;
			break;
		}
		++pCh;
	}
	delete [] hash;
	delete pCh;
	return result;
}

void FirstNotRepeatingCharTest() {
	char A[] = "accabffded";
	printf("%c\n", FirstNotRepeatingChar(A));
}


#endif /* FIRSTNOTREPEATINGCHAR_H_ */
