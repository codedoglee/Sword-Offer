#ifndef INVERSEPAIRS_H_
#define INVERSEPAIRS_H_

/*
 * 数组中的逆序对
 * 题目：在数组中的两个数字如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
 * 输入一个数组，求出这个数组中的逆序对的总数。
 */
int InversePairsCore(int* data, int* copy, int start, int end) {
	if (start == end) {
		copy[start] = data[start];
		return 0;
	}
	int length = (end - start) / 2;
	//关键点，copy数据（排好序的数据）作为下次的初始数据
	int left = InversePairsCore(copy, data, start, start + length);
	int right = InversePairsCore(copy, data, start + length + 1, end);
	int p1 = start + length; //将p1初始化为前半段最后一个数字的下标
	int p2 = end; //将p2初始化为后半段最后一个数字的下标
	int p3 = end; //从后向前拷贝
	int count = 0;
	while (p1 >= start && p2 >= start + length + 1) {
		if (data[p1] > data[p2]) {
			count += p2 - start - length;
			copy[p3--] = data[p1--];
		}
		else {
			copy[p3--] = data[p2--];
		}
	}
	while (p1 >= start) {
		copy[p3--] = data[p1--];
	}
	while (p2 >= start + length + 1) {
		copy[p3--] = data[p2--];
	}
	for (int i = 0; i < 4; ++i) {
		printf("%d\t", copy[i]);
	}
	printf("\n");
	return left + right + count;
}

int InversePairs(int* numbers, int length) {
	if (numbers == 0 || length <= 0) {
		return 0;
	}
	int* copy = new int[length];
	for (int i = 0; i <length; ++i) {
		copy[i] = numbers[i];
	}
	int count = InversePairsCore(numbers, copy, 0, length-1);
	delete [] copy;
	return count;
}

void InversePairsTest() {
	int A[] = {7,5,6,4};
	printf("%d\n", InversePairs(A, 4));
}


#endif /* INVERSEPAIRS_H_ */
