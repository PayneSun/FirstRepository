/*
 * prog_01_07.cpp
 * 2018/2/2
 */

#include <cstdio>

int main() {
	int n, m;

	scanf("%d", &n);
	m = (n % 10) * 100 + (n / 10 % 10) * 10 + (n / 100);
	printf("%03d\n", m);

	return 0;
}
