#ifndef VERIFYSEQUENCEOFBST_H_
#define VERIFYSEQUENCEOFBST_H_

/**
 * ��Ŀ������һ���������飬�жϸ������ǲ���ĳ�����������ĺ��������Ľ����
 * ������򷵻�true�����򷵻�false���������������������������ֶ�������ͬ��
 */
#include <stdio.h>

bool VerifySequenceofBST(int* sequence, int nLength) {
	if (sequence == 0 || nLength <= 0) {
		return false;
	}

	// ���ڵ�ֵ
	int rootValue = sequence[nLength-1];

	// �ڶ������������������Ľ��С�ڸ��ڵ�
	int i = 0;
	for (; i < nLength; ++i) {
		if (sequence[i] > rootValue) {
			break;
		}
	}

	// �ڶ������������������Ľ����ڸ��ڵ�
	int j = i;
	for (; j < nLength-1; ++j) {
		if (sequence[i] <= rootValue) {
			return false;
		}
	}

	// �ж��������ǲ��Ƕ���������
	bool left = false;
	if (i > 0) {
		left = VerifySequenceofBST(sequence, i);
	}

	// �ж��������ǲ��Ƕ���������
	bool right = false;
	if (i < nLength-1) {
		right = VerifySequenceofBST(sequence + i, nLength-1-i);
	}

	return (left && right);
}


#endif /* VERIFYSEQUENCEOFBST_H_ */
