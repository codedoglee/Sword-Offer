#ifndef JOSEPHUS_H_
#define JOSEPHUS_H_

/*
 * 题目：1,2,...,n-1,n这n个数字排成一个圆圈，从数字1开始每次从这个圆圈里删除第m个数字。
 * 求出这个圆圈里剩下的最后一个数字。
 */
#include <stdio.h>
#include <list>

struct Node {
	int num;
	Node *next;
	Node(int n) : num(n), next(0) {};
};

Node* JosephusList(Node *head, int m) {
	if (head == 0 || head->next == head || m <= 0) {
		return head;
	}
	Node *pre = head;
	while (pre->next != head) {
		pre = pre->next;
	}
	Node *cur = head;
	int i = 1;
	while (cur->next != cur) {
		if (i == m) {
			pre->next = cur->next;
			delete cur;
			cur = pre->next;
			i = 1;
		}
		else {
			++i;
			pre = pre->next;
			cur = cur->next;
		}
	}
	return cur;
}

int JosephusArray(int n, int m) {
	if (n <= 0 || m <= 0) {
		return -1;
	}
	int *help = new int[n];
	for (int i = 0; i < n; ++i) {
		help[i] = 1;
	}
	int count = 0; //死亡人数
	int i = 1; //循环计数
	int j = 0; //同步下标
	while (true) {
		if (i == m) {
			help[j] = 0;
			i = 1;
			while (help[j] == 0) {
				++j;
				j = j % n;
			}
			++count;
		}
		else {
			++i;
			++j;
			j = j % n;
			while (help[j] == 0) {
				++j;
				j = j % n;
			}
		}
		if (count == n-1) {
			break;
		}
	}
	int result = 0;
	for (int i = 0; i < n; ++i) {
		if (help[i] == 1) {
			result = i+1;
			break;
		}
	}
	delete[] help;
	return result+1;
}

int Josephus(int n, int m) {
	if (n <= 0 || m <= 0) {
		return -1;
	}
	unsigned int i = 0;
	std::list<int> numbers;
	for (int i = 1; i <= n; ++i) {
		numbers.push_back(i);
	}
	std::list<int>::iterator cur = numbers.begin();
	while (numbers.size() > 1) {
		for (int i = 1; i < m; ++i) {
			++cur;
			if (cur == numbers.end()) {
				cur = numbers.begin();
			}
		}
		std::list<int>::iterator next = cur + 1;
		if (next == numbers.end()) {
			next = numbers.begin();
		}
		numbers.erase(cur);
		cur = next;
	}
	return *cur;
}

int JosephusMath(int n, int m) {
	if (n <= 0 || m <= 0) {
		return -1;
	}
	int last = 0;
	for (int i = 2; i <= n; ++i) {
		last = (last + m) % i;
	}
	return last;
}


#endif /* JOSEPHUS_H_ */
