#ifndef PRINTMATRIXCIRCLE_H_
#define PRINTMATRIXCIRCLE_H_

/*
 * 题目：输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。
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
		// 从左向右打印
		if (startX <= endX) {
			for (int i = startY; i <= endY; ++i) {
				printf("%d\t", numbers[startX][i]);
			}
		}
		++startX;

		// 从上向下打印
		if (startY <= endY) {
			for (int i = startX; i <= endX; ++i) {
				printf("%d\t", numbers[i][endY]);
			}
		}
		--endY;

		// 从右向左打印
		if (startX <= endX) {
			for (int i = endY; i >= startY; --i) {
				printf("%d\t", numbers[endX][i]);
			}
		}
		--endX;

		// 从下向上打印
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
