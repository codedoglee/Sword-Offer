#ifndef PRINTMATRIXCIRCLE_H_
#define PRINTMATRIXCIRCLE_H_

/*
 * ��Ŀ������һ�����󣬰��մ���������˳ʱ���˳�����δ�ӡ��ÿһ�����֡�
 */
#include <stdio.h>

void PrintMatrixCircle(int** numbers, int rows, int columns) {
	if (numbers == 0 || *numbers == 0 || rows <= 0 || columns <= 0) {
		return;
	}
	int startX = 0;
	int startY = 0;
	int endX = rows-1;
	int endY = columns-1;

	while (startX <= endX && startY <= endY) {
		// �������Ҵ�ӡ
		if (startX <= endX) {
			for (int i = startY; i <= endY; ++i) {
				printf("%d\t", numbers[startX][i]);
			}
		}
		++startX;

		// �������´�ӡ
		if (startY <= endY) {
			for (int i = startX; i <= endX; ++i) {
				printf("%d\t", numbers[i][endY]);
			}
		}
		--endY;

		// ���������ӡ
		if (startX <= endX) {
			for (int i = endY; i >= startY; --i) {
				printf("%d\t", numbers[endX][i]);
			}
		}
		--endX;

		// �������ϴ�ӡ
		if (startY <= endY) {
			for (int i = endX; i >= startX; --i) {
				printf("%d\t", numbers[i][startY]);
			}
		}
		++startY;
	}
}

void PrintMatrixCircleTest() {
	int A[3][4] = {
		{1,2,3,4},
		{5,6,7,8},
	    {9,10,11,12}
	};
	int* B[3];
	B[0] = A[0];
	B[1] = A[1];
	B[2] = A[2];
	PrintMatrixCircle(B, 3, 4);
}


#endif /* PRINTMATRIXCIRCLE_H_ */
