#ifndef STREAMMEDIAN_H_
#define STREAMMEDIAN_H_

/*
 * ����������λ��
 * �����ѣ�make_heap(_First, _Last, _Comp)��Ĭ���ǽ������ѵġ������ڵ�������������greater<T>()�õ���С�ѡ�
 * �ڶ���������ݣ�push_heap (_First, _Last)��Ҫ���������м������ݣ��ٵ���push_heap()��
 * �ڶ���ɾ�����ݣ�pop_heap(_First, _Last)��Ҫ�ȵ���pop_heap()����������ɾ�����ݡ�
 * ������sort_heap(_First, _Last)������֮��Ͳ�����һ���Ϸ���heap�ˡ�
 */
#include <vector>
#include <algorithm>
#include <exception>
#include <stdexcept>

template <typename T> class DynamicArray {
public:
	void Insert(T num) {
		//ż��
		if (((min.size() + max.size()) & 1) == 0) {
			if (max.size() > 0 && num < max[0]) {
				max.push_back(num);
				std::push_heap(max.begin(), max.end(), std::less<T>());

				num = max[0];

				std::pop_heap(max.begin(), max.end(), std::less<T>());
				max.pop_back();
			}
			min.push_back(num);
			push_heap(min.begin(), min.end(), std::greater<T>());
		}
		else {
			if (min.size() > 0 && min[0] < num) {
				min.push_back(num);
				std::push_heap(min.begin(), min.end(), std::greater<T>());

				num = min[0];

				std::pop_heap(min.begin(), min.end(), std::greater<T>());
				min.pop_back();
			}
			max.push_back(num);
			std::push_heap(max.begin(), max.end(), std::less<T>());
		}
	}

	T GetMedian() {
		int size = min.size() + max.size();
		if (size == 0) {
			std::exception e("No numbers are available.");
			throw e;
		}
		T median = 0;
		if ((size & 1) == 1) {
			median = min[0];
		}
		else {
			median = (min[0] + max[0]) / 2;
		}
		return median;
	}

private:
	std::vector<T> min;
	std::vector<T> max;
};


#endif /* STREAMMEDIAN_H_ */
