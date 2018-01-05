#ifndef REGULAREXPRESSIONMATCH_H_
#define REGULAREXPRESSIONMATCH_H_

/*
 * 正则表达式匹配
 * 题目：请实现一个函数用来匹配包含'.'和'*'的正则表达式。
 * 模式中的字符'.'表示任意一个字符，而'*'表示它前面的字符可以出现任意次（包括0次）。
 */
#include <stdio.h>

bool MatchCore(char* data, char* pattern) {
	if (*data == '\0' && *pattern == '\0') {
		return true;
	}
	if (*data != '\0' && *pattern == '\0') {
		return false;
	}
	//模式的下一个字符是'*'
	if (*(pattern+1) == '*') {
		//当前字符可以匹配，*匹配0个或1个字符，或者保持当前状态（匹配更多字符）。
		if (*data == *pattern || (*pattern == '.' && *data != '\0')) {
			return MatchCore(data, pattern+2) || MatchCore(data+1, pattern+2) || MatchCore(data+1, pattern);
		}
		//当前字符无法匹配，'*'只能匹配0个字符
		else {
			return MatchCore(data, pattern+2);
		}
	}
	//模式的下一个字符不是'*'
	if (*data == *pattern || (*pattern == '.' && *data != '\0')) {
		return MatchCore(data+1, pattern+1);
	}
	return false;
}

bool Match(char* data, char* pattern) {
	if (data == 0 || pattern == 0) {
		return false;
	}
	return MatchCore(data, pattern);
}


#endif /* REGULAREXPRESSIONMATCH_H_ */
