#ifndef MORETHANHALFNUMBER_H_
#define MORETHANHALFNUMBER_H_

/*
 * ��Ŀ����������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�룬���ҳ�������֡�
 *
 * �ⷨ����������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�㣬Ҳ����˵�����ֵĴ����������������ֳ��ִ����ĺͻ�Ҫ�ࡣ
 * ��˿��Կ����ڱ�����ʱ�򱣴�����ֵ��һ���������е�һ�����֣�һ���Ǵ����������Ǳ�������һ�����ֵ�ʱ��
 * �����һ�����ֺ�����֮ǰ�����������ͬ���������1�������ͬ���������1���������Ϊ�㣬������Ҫ������һ��
 * ���֣����Ѵ�����Ϊ1����������Ҫ�ҵ����ֳ��ֵĴ����������������ֳ��ֵĴ���֮�ͻ�Ҫ�࣬��ôҪ�ҵ����ֿ϶���
 * ���һ�ΰѴ�����Ϊ1ʱ��Ӧ�����֡�
 */
#include <stdio.h>

bool g_bInputInvalid = false; //ȫ�ֱ�������¼�����Ƿ�Ϸ�

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
