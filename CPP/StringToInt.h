#ifndef STRINGTOINT_H_
#define STRINGTOINT_H_

/*
 * 题目：把字符串转换为整数
 */
#include <stdio.h>

//状态枚举类型
enum Status { kValid = 0, kInvalid };
//默认状态
int g_nStatus = kValid;

long long StrToIntCore(const char* digit, bool minus) {
	long long num = 0;
	while (*digit != '\0') {
		int flag = minus ? -1 : 1;
		if (*digit >= '0' && *digit <= '9') {
			num = num * 10 + flag * (*digit - '0');
			//正整数上溢或者负整数下溢
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

	//处理第一个字符是不是负号
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
