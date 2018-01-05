#ifndef MAXINSLIDINGWINDOW_H_
#define MAXINSLIDINGWINDOW_H_

/*
 * 滑动窗口的最大值
 */
#include <stdio.h>
#include <vector>
#include <deque>

std::vector<int> MaxInSlidingWindow(const std::vector<int>& numbers, unsigned int size) {
	std::vector<int> result;
	if (numbers.size() < size || size <= 0) {
		return result;
	}
	std::deque<int> index;
	index.push_back(0);
	//初始化窗口，第一个窗口
	for (unsigned int i = 0; i < size; ++i) {
		while (!index.empty() && numbers[i] >= numbers[index.back()]) {
			index.pop_back();
		}
		index.push_back(i);
	}
	result.push_back(numbers[index.front()]);

	for (unsigned int i = size; i < numbers.size(); ++i) {
		//从后往前一次弹小于或等于当前值的值的下标
		while (!index.empty() && numbers[i] >= numbers[index.back()]) {
			index.pop_back();
		}
		//当前值下标从放入队尾
		index.push_back(i);
		//检验队列头部下标是不是过期（是不是窗口已经划过去）
		if (!index.empty() && index.front() <= (int)(i-size)) {
			index.pop_front();
		}
		//将队头下标存入结果
		result.push_back(numbers[index.front()]);
	}
	return result;
}

void MaxInSlidingWindowTest() {
	std::vector<int> v = {2,3,4,2,6,2,5,1};
	std::vector<int> result = MaxInSlidingWindow(v, 3);
	for (unsigned int i = 0; i < result.size(); ++i) {
		printf("%d\t", result[i]);
	}
}


#endif /* MAXINSLIDINGWINDOW_H_ */
