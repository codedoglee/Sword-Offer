#ifndef MAXINSLIDINGWINDOW_H_
#define MAXINSLIDINGWINDOW_H_

/*
 * �������ڵ����ֵ
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
	//��ʼ�����ڣ���һ������
	for (unsigned int i = 0; i < size; ++i) {
		while (!index.empty() && numbers[i] >= numbers[index.back()]) {
			index.pop_back();
		}
		index.push_back(i);
	}
	result.push_back(numbers[index.front()]);

	for (unsigned int i = size; i < numbers.size(); ++i) {
		//�Ӻ���ǰһ�ε�С�ڻ���ڵ�ǰֵ��ֵ���±�
		while (!index.empty() && numbers[i] >= numbers[index.back()]) {
			index.pop_back();
		}
		//��ǰֵ�±�ӷ����β
		index.push_back(i);
		//�������ͷ���±��ǲ��ǹ��ڣ��ǲ��Ǵ����Ѿ�����ȥ��
		if (!index.empty() && index.front() <= (int)(i-size)) {
			index.pop_front();
		}
		//����ͷ�±������
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
