#ifndef MORETHANHALFNUMBER_H_
#define MORETHANHALFNUMBER_H_

/*
 * 题目：数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
 *
 * 解法：数组中有一个数字出现的次数超过数组长度的一般，也就是说它出现的次数比其他所有数字出现次数的和还要多。
 * 因此可以考虑在便利的时候保存两个值：一个是数组中的一个数字，一个是次数。当我们遍历到下一个数字的时候，
 * 如果下一个数字和我们之前保存的数字相同，则次数加1；如果不同，则次数减1。如果次数为零，我们需要保存下一个
 * 数字，并把次数设为1。由于我们要找的数字出现的次数比其他所有数字出现的次数之和还要多，那么要找的数字肯定是
 * 最后一次把次数设为1时对应的数字。
 */
#include <stdio.h>

bool g_bInputInvalid = false; //全局变量，记录输入是否合法

bool CheckInvalid(int* numbers, int length) {
	if (numbers == 0 || length <= 0) {
		g_bInputInvalid = true;
		return 0;
	}
	return g_bInputInvalid;
}

bool IsMoreThanHalf(int* numbers, int length, int num) {
	int times = 0;
	for (int i = 0; i < length; ++i) {
		if (numbers[i] == num) {
			++times;
		}
	}
	bool isMoreThanHalf = true;
	if ((times << 1) <= length) {
		g_bInputInvalid = false;
		isMoreThanHalf = false;
	}
	return isMoreThanHalf;
}

int MoreThanHalfNumber(int* numbers, int length) {
	if (!CheckInvalid(numbers, length)) {
		return 0;
	}
	int num = numbers[0];
	int count = 1;
	for (int i = 1; i < length; ++i) {
		if (count == 0) {
			num = numbers[i];
			++count;
		}
		else if (num == numbers[i]) {
			++count;
		}
		else {
			--count;
		}
	}
	if (!IsMoreThanHalf(numbers, length, num)) {
		return 0;
	}
	return num;
}


#endif /* MORETHANHALFNUMBER_H_ */
