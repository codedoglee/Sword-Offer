#ifndef REGULAREXPRESSIONMATCH_H_
#define REGULAREXPRESSIONMATCH_H_

/*
 * ������ʽƥ��
 * ��Ŀ����ʵ��һ����������ƥ�����'.'��'*'��������ʽ��
 * ģʽ�е��ַ�'.'��ʾ����һ���ַ�����'*'��ʾ��ǰ����ַ����Գ�������Σ�����0�Σ���
 */
#include <stdio.h>

bool MatchCore(char* data, char* pattern) {
	if (*data == '\0' && *pattern == '\0') {
		return true;
	}
	if (*data != '\0' && *pattern == '\0') {
		return false;
	}
	//ģʽ����һ���ַ���'*'
	if (*(pattern+1) == '*') {
		//��ǰ�ַ�����ƥ�䣬*ƥ��0����1���ַ������߱��ֵ�ǰ״̬��ƥ������ַ�����
		if (*data == *pattern || (*pattern == '.' && *data != '\0')) {
			return MatchCore(data, pattern+2) || MatchCore(data+1, pattern+2) || MatchCore(data+1, pattern);
		}
		//��ǰ�ַ��޷�ƥ�䣬'*'ֻ��ƥ��0���ַ�
		else {
			return MatchCore(data, pattern+2);
		}
	}
	//ģʽ����һ���ַ�����'*'
	if (*data == *pattern || (*pattern == '.' && *data != '\0')) {
		return MatchCore(data+1, pattern+1);
	}
	return false;
}

bool Match(char* data, char* pattern) {
	if (data == 0 || pattern == 0) {
		return false;
	}
	return MatchCore(data, pattern);
}


#endif /* REGULAREXPRESSIONMATCH_H_ */
