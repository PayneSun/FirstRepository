// prog_04_06.cpp
// 2019.05.05

#include <cstdio>

void swap(int *a, int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}


int main()
{
	int a = 3, b = 4;
	swap(&a, &b);
	printf("%d %d\n", a, b);

	return 0;
}
