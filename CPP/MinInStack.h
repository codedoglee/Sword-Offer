#ifndef MININSTACK_H_
#define MININSTACK_H_

/*
 * 题目：定义站的数据结构，请在该类型中实现一个能够得到栈的最小元素的min函数。
 * 在该函数中，调用min、push、pop的时间复杂度都是O(1)。
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
