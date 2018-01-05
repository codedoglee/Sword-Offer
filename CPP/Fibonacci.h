#ifndef FIBONACCI_H_
#define FIBONACCI_H_

#include <stdio.h>

long long Fibonacci(unsigned long n) {
	if (n == 0) {
		return 0;
	}
	if (n == 1 || n == 2) {
		return 1;
	}

	long long fib1 = 1;
	long long fib2 = 1;
	long long fib3 = 0;
	for (unsigned int i = 2; i <= n; ++i) {
		fib3 = fib1 + fib2;
		fib1 = fib2;
		fib2 = fib3;
	}
	return fib3;
}


#endif /* FIBONACCI_H_ */
