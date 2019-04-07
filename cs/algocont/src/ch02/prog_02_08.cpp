/*
 * prog_02_08.cpp
 * 2018/2/3
 */

/*
#include <stdio.h>
#include <time.h>

int main() {
	const int MOD = 1000000;
	int n, S = 0;
	scanf("%d", &n);
	for (int i = 0; i <= n; ++i) {
		int fac = 1;
		for (int j = 1; j <= i; ++j) {
			fac = (fac * j % MOD);
		}
		S = (S + fac) % MOD;
	}
	printf("%d\n", S % 1000000);
	printf("Time used = %.2f\n", (double)clock() / CLOCKS_PER_SEC);
	return 0;
}
*/