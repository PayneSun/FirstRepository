/*
 * solu_01_05.cpp
 * 2018/2/2
 */

#include <cstdio>

int main() {
	int n;
	scanf("%d", &n);

	if (n * 95 >= 300) {
		printf("%.3lf\n", n * 95 * 0.85);
	} else {
		printf("%.3lf\n", n * 95 * 1.0);
	}
	
	return 0;
}
