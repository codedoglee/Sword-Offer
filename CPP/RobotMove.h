#ifndef ROBOTMOVE_H_
#define ROBOTMOVE_H_

/*
 * 机器人运动范围
 * 题目：地上有一个m行n列的方格。当一个机器人从坐标(0,0)的各自开始移动，它每一次可以向左、右、上、下移动一格，
 * 但不能进入行坐标和列坐标的数位之和大于k的格子。请问该机器人能够到达多少个格子？（不含负值）
 * 例如：当k为18时，机器人能够进入方格(35,37)，因为3+5+3+7=18。但它不能进入方格(35,38)，因为3+5+3+8=19。
 */
#include <stdio.h>

int GetDigitSum(int num) {
	int sum = 0;
	while (num != 0) {
		sum += num % 10;
		num = num / 10;
	}
	return sum;
}

bool CheckIn(int rows, int cols, int k, int row, int col, bool* visited) {
	if (row >= 0 && col >= 0 && row < rows && col < cols &&
		GetDigitSum(row) + GetDigitSum(col) <= k && !visited[row * cols + row]) {
		return true;
	}
	return false;
}

int MovingCount(int rows, int cols, int k, int row, int col, bool* visited) {
	int count = 0;
	if (CheckIn(rows, cols, k, row, col, visited)) {
		visited[row * cols + row] = true;
		count = 1 + MovingCount(rows, cols, k, row+1, col, visited)
				  + MovingCount(rows, cols, k, row-1, col, visited)
				  + MovingCount(rows, cols, k, row, col+1, visited)
				  + MovingCount(rows, cols, k, row, col-1, visited);
	}
	return count;
}

int RobotMovingCount(int rows, int cols, int k) {
	bool* visited = new bool[rows * cols];
	for (int i = 0; i < rows * cols; ++i) {
		visited[i] = false;
	}
	int count = MovingCount(rows, cols, k, 0, 0, visited);
	delete[] visited;
	return count;
}


#endif /* ROBOTMOVE_H_ */
