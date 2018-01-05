#ifndef POWER_H_
#define POWER_H_

/*
 * ��Ŀ��ʵ�ֺ���double Power(double base, int exponent)����base��exponent�η���
 * ����ʹ�ÿ⺯����ͬʱ����Ҫ���Ǵ������⡣
 */
#include <stdio.h>
#include <stdexcept>

bool DoubleEqual(double d1, double d2) {
	if (d1 - d2 > -0.000000001 && d1 - d2 < 0.000000001) {
		return true;
	}
	else {
		return false;
	}
}

double PowerWithUnsignedExponent(double base, unsigned int exponent) {
	if (exponent == 0) {
		return 1;
	}
	if (exponent == 1) {
		return base;
	}
	double result = PowerWithUnsignedExponent(base, exponent >> 1);
	result *= result;
	if (exponent & 0x1 == 1) {
		result *= base;
	}
	return result;
}

double Power(double base, int exponent) {
	if (DoubleEqual(base, 0.0) && exponent < 0) {
		std::runtime_error err("Invalid input!");
		throw err;
	}
	unsigned int absExponent = (unsigned int)(exponent);
	if (exponent < 0) {
		absExponent = (unsigned int)(-exponent);
	}
	double result = PowerWithUnsignedExponent(base, absExponent);
	if (exponent < 0) {
		result = 1.0 / result;
	}
	return result;
}


#endif /* POWER_H_ */
