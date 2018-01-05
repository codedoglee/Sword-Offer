#ifndef QUEUEWITHTWOSTACKS_H_
#define QUEUEWITHTWOSTACKS_H_

#include <stdio.h>
#include <stack>
#include <stdexcept>

template <typename T> class MyQueue {
public:
	MyQueue();
	~MyQueue();

	void Push(const T& element);
	void Pop();
	bool Empty();
	std::size_t size();
	T& Front();

private:
	std::stack<T> stack1;
	std::stack<T> stack2;
};

template <typename T>
MyQueue<T>::MyQueue() {}

template <typename T>
MyQueue<T>::~MyQueue() {}

template <typename T>
void MyQueue<T>::Push(const T& element) {
	stack2.push(element);
}

template <typename T>
void MyQueue<T>::Pop() {
	if (!stack1.empty()) {
		stack1.pop();
	}
	else {
		if (stack2.empty()) {
			std::runtime_error err("The queue has none element!");
			throw err;
		}
		while (!stack2.empty()) {
			stack1.push(stack2.top());
			stack2.pop();
		}
		stack1.pop();
	}
}

template <typename T>
bool MyQueue<T>::Empty() {
	return (stack1.empty() && stack2.empty());
}

template <typename T>
std::size_t MyQueue<T>::size() {
	return stack1.size() + stack2.size();
}

template <typename T>
T& MyQueue<T>::Front() {
	if (!stack1.empty()) {
		return stack1.top();
	}
	else {
		if (stack2.empty()) {
			std::runtime_error err("The queue has none element!");
			throw err;
		}
		else {
			while (!stack2.empty()) {
				stack1.push(stack2.top());
				stack2.pop();
			}
			return stack1.top();
		}
	}
}

void MyQueueTest() {
	MyQueue<int> q;
	q.Push(1);
	q.Push(2);
	printf("%d\n", q.Front());
	q.Push(3);
	q.Push(4);
	q.Pop();
	q.Pop();
	printf("%d\n", q.Front());
}


#endif /* QUEUEWITHTWOSTACKS_H_ */
