#ifndef ISNUMERIC_H_
#define ISNUMERIC_H_

/*
 * 表示数值的字符串
 * 题目：请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。
 * 例如，字符串“+100”、“5e2”、“-123”、“3.14159”及“-1E-10”都表示数值。
 */
#include <stdio.h>

//用来扫描字符串中的0-9的数位（要改变指针的数值，参数为二级指针）
int ScanDigit(char** data) {
	int count = 0;
	while (**data != '\0' && **data >= '0' && **data <= '9') {
		++(*data);
		++count;
	}
	return count;
}

bool IsExponent(char** data) {
	if (**data == '\0') {
		return false;
	}
	if (**data == '+' || **data == '-') {
		++(*data);
	}
	if (**data == '\0'|| **data == '0') {
		return false;
	}
	ScanDigit(data);
	return (**data == '\0') ? true : false;
}

bool IsNumeric(char* data) {
	if (data == 0) {
		return false;
	}
	if (*data == '+' || *data == '-') {
		++data;
	}
	if (*data == '\0') {
		return false;
	}
	if (*data == '0' && (*(data+1) == '\0' || *(data+1) != '.')) {
		return false;
	}
	bool numeric = true;
	ScanDigit(&data);
	if (*data != '\0') {
		//小数
		if (*data == '.') {
			++data;
			if (ScanDigit(&data) == 0) {
				return false;
			}
			if (*data == 'e' || *data == 'E') {
				numeric = IsExponent(&(++data));
			}
		}
		else if (*data == 'e' || *data == 'E') {
			numeric = IsExponent(&(++data));
		}
		else {
			numeric = false;
		}
	}
	return (numeric && *data == '\0');
}

void IsNumericTest() {
	char S[] = "1.2e2";
	printf("%d\n", IsNumeric(S));
}


#endif /* ISNUMERIC_H_ */
