#ifndef STRINGPERMUTATION_H_
#define STRINGPERMUTATION_H_

/*
 * ��Ŀ������һ���ַ�������ӡ�����ַ������ַ����������С�
 */
#include <stdio.h>

void Permutation(char* pStr, char* pBegin) {
	if (*pBegin == '\0') {
		printf("%s\n", pStr);
	}
	else {
		for (char* pCh = pBegin; *pCh != '\0'; ++pCh) {
			char temp = *pCh;
			*pCh = *pBegin;
			*pBegin = temp;

			Permutation(pStr, pBegin+1);

			temp = *pCh;
			*pCh = *pBegin;
			*pBegin = temp;
		}
	}
}

void Permutation(char* pStr) {
	if (pStr == 0) {
		return;
	}
	Permutation(pStr, pStr);
}

void StringPermutationTest() {
	char str[4] = "ABC";
	Permutation(str);
}


#endif /* STRINGPERMUTATION_H_ */
