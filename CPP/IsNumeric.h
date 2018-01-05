#ifndef ISNUMERIC_H_
#define ISNUMERIC_H_

/*
 * ��ʾ��ֵ���ַ���
 * ��Ŀ����ʵ��һ�����������ж��ַ����Ƿ��ʾ��ֵ������������С������
 * ���磬�ַ�����+100������5e2������-123������3.14159������-1E-10������ʾ��ֵ��
 */
#include <stdio.h>

//����ɨ���ַ����е�0-9����λ��Ҫ�ı�ָ�����ֵ������Ϊ����ָ�룩
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
		//С��
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
