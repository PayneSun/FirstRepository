/*
 * solu_01_06.cpp
 * 2018/2/2
 */

#include <cstdio>

int main() {
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);

	if (a*a == b*b + c*c || b*b == a*a + c*c || c*c == b*b + a*a) {
		printf("yes\n");
	} else if (a + b > c && a + c > b && c + b > a) {
		printf("no\n");
	} else {
		printf("not a triangle\n");
	}

	return 0;
}
