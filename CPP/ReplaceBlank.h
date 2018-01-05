#ifndef REPLACEBLANK_H_
#define REPLACEBLANK_H_

/*
 * ��Ŀ����ʵ��һ�����������ַ����е�ÿ���ո��滻��"%20"��
 * ��������"We are happy."�������"We%20are%20happy."��
 */
#include <stdio.h>

/*
 * @para str �ַ�����
 * @para length �ַ������������
 */
void ReplaceBlank(char *str, int length) {
	if (str == 0 || length <= 0) {
		return;
	}
	int oldLength = 0;
	int blankNum = 0;
	int i = 0;
	while (str[i] != '\0') {
		++oldLength;
		if (str[i] == ' ') {
			++blankNum;
		}
		++i;
	}
	int newLength = oldLength + 2 * blankNum;
	if (newLength > length) {
		return;
	}
	int indexOfOld = oldLength;
	int indexOfNew = newLength;
	while (indexOfOld >= 0 && indexOfNew >= indexOfOld) {
		if (str[indexOfOld] == ' ') {
			str[indexOfNew--] = '0';
			str[indexOfNew--] = '2';
			str[indexOfNew--] = '%';
		}
		else {
			str[indexOfNew--] = str[indexOfOld];
		}
		--indexOfOld;
	}
}


#endif /* REPLACEBLANK_H_ */
