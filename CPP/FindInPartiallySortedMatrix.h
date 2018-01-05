#ifndef FINDINPARTIALLYSORTEDMATRIX_H_
#define FINDINPARTIALLYSORTEDMATRIX_H_

/*
 * 题目：在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
 * 请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
 */
#include <stdio.h>

/*
 * @para matrix 一维数组表示的二维数组
 * @para rows 数组行数
 * @para columns 数组列数
 * @para number 要查找的数字
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
