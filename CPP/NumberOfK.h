#ifndef NUMBEROFK_H_
#define NUMBEROFK_H_

/*
 * 题目：统计一个数字在排序数组中出现的次数。
 */
#include <stdio.h>

int GetFirstKIndex(int* data, int k, int start, int end) {
	if (start > end) {
		return -1;
	}
	int mid = (start + end) / 2;
	if (data[mid] == k) {
		if (mid == 0 || (mid > 0 && data[mid-1] < k)) {
			return mid;
		}
		else {
			end = mid - 1;
		}
	}
	else if (data[mid] > k) {
		end = mid - 1;
	}
	else {
		start = mid + 1;
	}
	return GetFirstKIndex(data, k, start, end);
}

int GetLastKIndex(int* data, int k, int start, int end) {
	if (start > end) {
		return -1;
	}
	int mid = (start + end) / 2;
	if (data[mid] == k) {
		if (mid == end || (mid < end && data[mid+1] > k)) {
			return mid;
		}
		else {
			start = mid + 1;
		}
	}
	else if (data[mid] > k) {
		end = mid - 1;
	}
	else {
		start = mid + 1;
	}
	return GetLastKIndex(data, k, start, end);
}

int GetNumberOfK(int* data, int length, int k) {
	int number = 0;
	if (data == 0 || length <= 0) {
		return 0;
	}
	int first = GetFirstKIndex(data, k, 0, length-1);
	int last = GetLastKIndex(data, k, 0, length-1);
	if (first >= 0 && last >= 0) {
		number = last - first + 1;
	}
	return number;
}

void GetNumberOfKTest() {
	int A[] = {1,2,2,2,3,3,4,5};
	printf("number 2: %d\n", GetNumberOfK(A, 8, 2));
	printf("number 6: %d\n", GetNumberOfK(A, 8, 6));
}


#endif /* NUMBEROFK_H_ */
