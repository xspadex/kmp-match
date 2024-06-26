// kmpMatch.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#define L 7
#define LL 37

//next数组含义：next[3]为str[3]之前的字符串的最长相同前后缀长度，仅next[0]为例外，赋值-1用以判定是否需要从头开始比较
void CalNext(char *str, int *next, int length) {
	next[0] = -1;
	next[1] = 0;
	int k = 0;
	for (int q = 1; q < length-1; q++) {
		while (k > -1 && str[k] != str[q]) {
			k = next[k];
		}
		k++;
		next[q+1] = k;
		if (str[q + 1] == str[k]) {
			next[q + 1] = next[k];
		}
	}
	return;
}

int KMP(char *lstr, int llen, char *sstr, int slen) {
	int next[L];
	CalNext(sstr, next, slen);
	for (int i = 0; i < L; i++) {
		std::cout << next[i] << " ";
	}
	std::cout << std::endl;
	int k = 0;
	for (int q = 0; q < llen; q++) {
		while (k>-1 && lstr[q] != sstr[k]) {
			k = next[k];
		}
		k++;
		if (k == L - 1) return q-L+2;
	}
	return -1;
}

int main()
{
	char lstr[LL+1] = "bacbababadababacambabacaddababacasdsd";
	char str[L+1] = "ababaca";
	int result;
	result = KMP(lstr, LL, str, L);
	std::cout << result;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
