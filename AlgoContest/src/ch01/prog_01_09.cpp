/*
 * prog_01_09.cpp
 * 2019/4/7
 */

#include <cstdio>

int main() {
	int a, b;
	scanf("%d%d", &a, &b);

	a = a + b;
	b = a - b;
	a = a - b;
	printf("%d %d\n", a, b);

	return 0;
}
