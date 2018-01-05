#ifndef DUPLICATENUMBERINARRAY_H_
#define DUPLICATENUMBERINARRAY_H_

/*
 * �������ظ�������
 * ��Ŀ����һ���˳���Ϊn����������������ֶ���0��n-1�ķ�Χ�ڡ�������ĳЩ�������ظ��ģ�
 * ����֪���м��������ظ��ˣ�Ҳ��֪��ÿ�������ظ��˼��Ρ����ҳ�����������һ���ظ������֡�
 */
#include <stdio.h>

bool DuplicateNumber(int* data, int length, int* duplicate) {
	if (data == 0 || length <= 0) {
		return false;
	}
	//���������Ƿ����Ҫ��
	for (int i = 0; i < length; ++i) {
		if (data[i] < 0 || data[i] >= length) {
			return false;
		}
	}
	for (int i = 0; i < length; ++i) {
		while (data[i] != i) {
			if (data[i] == data[data[i]]) {
				*duplicate = data[i];
				return true;
			}
			int temp = data[i];
			data[i] = data[data[i]];
			data[data[i]] = temp;
		}
	}
	return false;
}


#endif /* DUPLICATENUMBERINARRAY_H_ */
