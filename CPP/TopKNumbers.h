#ifndef TOPKNUMBERS_H_
#define TOPKNUMBERS_H_

/*
 * 题目：最小的K个数
 * 输入n个数字，找出其中最小的k个数。例如输入4、5、1、6、2、7、3、8这8个数字，
 * 则最小的4个数字是1、2、3、4。
 */
#include <stdio.h>
#include <stdexcept>
#include <set>

void Swap(int& p, int& q) {
	int temp = p;
	p = q;
	q = temp;
}

int Partition(int* input, int length, int start, int end) {
	if (input == 0 || length <= 0 || start < 0 || end > length) {
		std::runtime_error err("Invalid input!");
		throw err;
	}
	int mid = input[start];
	int i = start;
	for (int j = start+1; j < end; ++j) {
		if (input[j] < mid) {
			++i;
			Swap(input[i], input[j]);
		}
	}
	Swap(input[i], input[start]);
	return i;
}

void TopKNumber(int* input, int n, int* output, int k) {
	if (input == 0 || output == 0 || n <= 0 || k <= 0 || k > n) {
		return;
	}
	int start = 0;
	int end = n;
	int index = Partition(input, n, start, end);
	while (index != k-1) {
		if (index < k-1) {
			start = index+1;
			index = Partition(input, n, start, end);
		}
		else {
			end = index-1;
			index = Partition(input, n, start, end);
		}
	}
	for (int i = 0; i < k; ++i) {
		output[i] = input[i];
	}
}


typedef std::multiset<int, std::greater<int> > intSet;
typedef std::multiset<int, std::greater<int> >::iterator intSetIterator;
// 适用于大数据
void TopKNumber2(const std::vector<int>& data, intSet& leastNumber, int k) {
	leastNumber.clear();
	if (k <= 0 || data.size() < k) {
		return;
	}

	for (int i = 0; i < data.size(); ++i) {
		if (leastNumber.size() < k) {
			leastNumber.insert(data[i]);
		}
		else {
			intSetIterator it = leastNumber.begin();
			if (data[i] < *it) {
				leastNumber.erase(it);
				leastNumber.insert(data[i]);
			}
		}
	}

}

void TopKNumber() {
	int A[] = {4,1,5,7,2,6,3,8,9};
	int* B = new int[3];
	TopKNumber(A, 9, B, 3);
	for (int i = 0; i < 3; ++i) {
		printf("%d\t", B[i]);
	}
}


#endif /* TOPKNUMBERS_H_ */
