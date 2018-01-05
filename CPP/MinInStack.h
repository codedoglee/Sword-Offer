#ifndef MININSTACK_H_
#define MININSTACK_H_

/*
 * ��Ŀ������վ�����ݽṹ�����ڸ�������ʵ��һ���ܹ��õ�ջ����СԪ�ص�min������
 * �ڸú����У�����min��push��pop��ʱ�临�Ӷȶ���O(1)��
 */
#include <stdio.h>
#include <stack>

template <typename T>
class StackWithMin {
private:
	std::stack<T> stack1;
	std::stack<T> stack2;
public:
	void push(const T& element);
	void pop();
	T& top();
	bool empty();
	std::size_t size();
	T& min();
};

template <typename T> void StackWithMin<T>::push(const T& element) {
	if (empty()) {
		stack2.push(element);
	}
	else if (element < stack2.top()) {
		stack2.push(element);
	}
	else {
		stack2.push(stack2.top());
	}
	stack1.push(element);
}

template <typename T> void StackWithMin<T>::pop() {
	stack1.pop();
	stack2.pop();
}

template <typename T> T& StackWithMin<T>::top() {
	return stack1.top();
}

template <typename T> T& StackWithMin<T>::min() {
	return stack2.top();
}

template <typename T> std::size_t StackWithMin<T>::size() {
	return stack1.size();
}

template <typename T> bool StackWithMin<T>::empty() {
	return stack1.empty();
}

void StackWithMinTest() {
	StackWithMin<int> st;
	st.push(2);
	st.push(3);
	st.push(1);
	printf("%d\n", st.min());
	st.pop();
	printf("%d\n", st.min());
}


#endif /* MININSTACK_H_ */
