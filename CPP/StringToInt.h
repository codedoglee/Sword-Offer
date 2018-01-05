#ifndef STRINGTOINT_H_
#define STRINGTOINT_H_

/*
 * ��Ŀ�����ַ���ת��Ϊ����
 */
#include <stdio.h>

//״̬ö������
enum Status { kValid = 0, kInvalid };
//Ĭ��״̬
int g_nStatus = kValid;

long long StrToIntCore(const char* digit, bool minus) {
	long long num = 0;
	while (*digit != '\0') {
		int flag = minus ? -1 : 1;
		if (*digit >= '0' && *digit <= '9') {
			num = num * 10 + flag * (*digit - '0');
			//������������߸���������
			if ((!minus && num > 0x7FFFFFFF) || (minus && num < (signed int)0x80000000)) {
				num = 0;
				break;
			}
			++digit;
		}
		else {
			g_nStatus = kInvalid;
			num = 0;
			break;
		}
	}
	if (*digit == '\0') {
		g_nStatus = kValid;
	}
	return num;
}

int StrToInt(const char* str) {
	g_nStatus = kValid;
	long long num = 0;

	//�����һ���ַ��ǲ��Ǹ���
	if (str != 0 && *str != '\0') {
		bool minus = false;
		if (*str == '+') {
			++str;
		}
		else if (*str == '-') {
			++str;
			minus = true;
		}

		if (*str != '\0') {
			num = StrToIntCore(str, minus);
		}
	}
	return (int)num;
}


#endif /* STRINGTOINT_H_ */
