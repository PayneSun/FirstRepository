// prog_04_08.cpp
// 2019.05.13

#include <cstdio>

int sum(int *a, int n) {
	int ans = 0;
	for (int i = 0; i < sizeof(a); ++i) {
		ans += a[i];
	}

	return ans;
}
