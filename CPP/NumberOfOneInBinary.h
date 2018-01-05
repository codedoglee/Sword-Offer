#ifndef NUMBEROFONEINBINARY_H_
#define NUMBEROFONEINBINARY_H_

#include <stdio.h>

int NumberOfOne(int n) {
	int count = 0;
	unsigned int flag = 1;
	while (flag) {
		if (n & flag) {
			++count;
		}
		flag = flag << 1;
	}
	return count;
}

int NumberOfOne2(int n) {
	int count = 0;
	while (n) {
		++count;
		n = (n-1) & n;
	}
	return count;
}


#endif /* NUMBEROFONEINBINARY_H_ */
