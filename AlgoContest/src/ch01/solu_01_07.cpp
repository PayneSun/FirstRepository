/*
 * solu_01_07.cpp
 * 2018/2/2
 */

#include <cstdio>

int main() {
	int year;
	scanf("%d", &year);

	if (year % 4 == 0 && year % 400 != 0) {
		printf("yes\n");
	} else {
		printf("no\n");
	}

	return 0;
}
