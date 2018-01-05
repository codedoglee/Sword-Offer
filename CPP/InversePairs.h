#ifndef INVERSEPAIRS_H_
#define INVERSEPAIRS_H_

/*
 * �����е������
 * ��Ŀ���������е������������ǰ��һ�����ִ��ں�������֣����������������һ������ԡ�
 * ����һ�����飬�����������е�����Ե�������
 */
int InversePairsCore(int* data, int* copy, int start, int end) {
	if (start == end) {
		copy[start] = data[start];
		return 0;
	}
	int length = (end - start) / 2;
	//�ؼ��㣬copy���ݣ��ź�������ݣ���Ϊ�´εĳ�ʼ����
	int left = InversePairsCore(copy, data, start, start + length);
	int right = InversePairsCore(copy, data, start + length + 1, end);
	int p1 = start + length; //��p1��ʼ��Ϊǰ������һ�����ֵ��±�
	int p2 = end; //��p2��ʼ��Ϊ�������һ�����ֵ��±�
	int p3 = end; //�Ӻ���ǰ����
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
