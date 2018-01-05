#ifndef FINDINPARTIALLYSORTEDMATRIX_H_
#define FINDINPARTIALLYSORTEDMATRIX_H_

/*
 * ��Ŀ����һ����ά�����У�ÿһ�ж����մ����ҵ�����˳������ÿһ�ж����մ��ϵ��µ�����˳������
 * �����һ������������������һ����ά�����һ���������ж��������Ƿ��и�������
 */
#include <stdio.h>

/*
 * @para matrix һά�����ʾ�Ķ�ά����
 * @para rows ��������
 * @para columns ��������
 * @para number Ҫ���ҵ�����
 */
bool Find(int* matrix, int rows, int columns, int number) {
	bool found = false;
	if (matrix == 0 || rows <=0 || columns <= 0) {
		return found;
	}
	int row = 0;
	int column = columns-1;
	while (row < rows && column >= 0) {
		if (matrix[row * columns + column] == number) {
			found = true;
			break;
		}
		else if (matrix[row * columns + column] > number) {
			--column;
		}
		else {
			++row;
		}
	}
	return found;
}


#endif /* FINDINPARTIALLYSORTEDMATRIX_H_ */
