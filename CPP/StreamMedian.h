#ifndef STREAMMEDIAN_H_
#define STREAMMEDIAN_H_

/*
 * 数据流的中位数
 * 建立堆：make_heap(_First, _Last, _Comp)，默认是建立最大堆的。可以在第三个参数传入greater<T>()得到最小堆。
 * 在堆中添加数据：push_heap (_First, _Last)，要先在容器中加入数据，再调用push_heap()。
 * 在堆中删除数据：pop_heap(_First, _Last)，要先调用pop_heap()再在容器中删除数据。
 * 堆排序：sort_heap(_First, _Last)，排序之后就不再是一个合法的heap了。
 */
#include <vector>
#include <algorithm>
#include <exception>
#include <stdexcept>

template <typename T> class DynamicArray {
public:
	void Insert(T num) {
		//偶数
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
