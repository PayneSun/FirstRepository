// prog_04_09.cpp
// 2019.05.13

#include <cstdio>

int sum(int *begin, int *end) {
	int n = end - begin;
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		ans += begin[i];
	}

	return ans;
}
