#ifndef STACKPUSHPOPORDER_H_
#define STACKPUSHPOPORDER_H_

/*
 * 题目：输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。
 * 假设所有的数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，序列4,5,6,2,1是该栈序列对应的一个弹出序列，
 * 但4,3,5,1,2就不可能是该压栈序列的弹出序列。
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
