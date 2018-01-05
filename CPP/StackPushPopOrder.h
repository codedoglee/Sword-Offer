#ifndef STACKPUSHPOPORDER_H_
#define STACKPUSHPOPORDER_H_

/*
 * ��Ŀ�����������������У���һ�����б�ʾջ��ѹ��˳�����жϵڶ��������Ƿ�Ϊ��ջ�ĵ���˳��
 * �������е����־�����ȡ���������1,2,3,4,5��ĳջ��ѹ��˳������4,5,6,2,1�Ǹ�ջ���ж�Ӧ��һ���������У�
 * ��4,3,5,1,2�Ͳ������Ǹ�ѹջ���еĵ������С�
 */
#include <stdio.h>
#include <stack>

bool IsPopOrder(int* pPush, int* pPop, int nLength) {
	if (pPush == 0 || pPop == 0 || nLength <= 0) {
		return false;
	}

	bool ispop = false;
	bool allPushed = false;

	const int* pNextPush = pPush;
	const int* pNextPop = pPop;

	std::stack<int> stackData;

	while (pNextPop - pPop < nLength) {
		while (stackData.empty() || stackData.top() != *pNextPop) {
			if (pNextPush - pPush == nLength) {
				allPushed = true;
				break;
			}
			stackData.push(*pNextPush);
			++pNextPush;
		}
		if (allPushed) {
			break;
		}
		stackData.pop();
		++pNextPop;
	}
	if (stackData.empty() && pNextPop - pPop == nLength) {
		ispop = true;
	}
	return ispop;
}

void IsPopOrderTest() {
	int A[] = {1,2,3,4,5};
	int B[] = {4,5,3,2,1};
	int C[] = {4,3,5,1,2};
	printf("%d\n", IsPopOrder(A, B, 5));
	printf("%d\n", IsPopOrder(A, C, 5));
}


#endif /* STACKPUSHPOPORDER_H_ */
