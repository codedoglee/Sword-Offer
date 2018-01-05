#ifndef PRINTONETOMAXOFNDIGITS_H_
#define PRINTONETOMAXOFNDIGITS_H_

#include <stdio.h>
#include <cstring>

void Increment(char* number) {
	int takeOver = 0;	// ½øÎ»Öµ
	int len = strlen(number);
	for (int i = len - 1; i >= 0; --i) {
		int sum = number[i] - '0' + takeOver;
		if (i == len-1) {
			++sum;
		}
		if (sum >= 10) {
			takeOver = 1;
			sum -= 10;
			number[i] = '0' + sum;
		}
		else {
			number[i] = '0' + sum;
			break;
		}
	}
}

void PrintNumber(char* number) {
	int len = strlen(number);
	bool begin = false;
	for (int i = 0; i < len; ++i) {
		if (number[i] != '0') {
			begin = true;
		}
		if (begin) {
			printf("%c", number[i]);
		}
	}
	printf("\n");
}

void PrintOneToMaxOfNDigits(int n) {
	if (n <= 0) {
		return;
	}
	char *number = new char[n+2];
	memset(number, '0', n+1);
	number[n+1] = '\0';
	while (number[0] == '0') {
		Increment(number);
		PrintNumber(number);
	}
	delete [] number;
}

void PrintOneToMaxOfNDigitsTest() {
	PrintOneToMaxOfNDigits(2);
}


#endif /* PRINTONETOMAXOFNDIGITS_H_ */
