#ifndef ROBOTMOVE_H_
#define ROBOTMOVE_H_

/*
 * �������˶���Χ
 * ��Ŀ��������һ��m��n�еķ��񡣵�һ�������˴�����(0,0)�ĸ��Կ�ʼ�ƶ�����ÿһ�ο��������ҡ��ϡ����ƶ�һ��
 * �����ܽ�������������������λ֮�ʹ���k�ĸ��ӡ����ʸû������ܹ�������ٸ����ӣ���������ֵ��
 * ���磺��kΪ18ʱ���������ܹ����뷽��(35,37)����Ϊ3+5+3+7=18���������ܽ��뷽��(35,38)����Ϊ3+5+3+8=19��
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
