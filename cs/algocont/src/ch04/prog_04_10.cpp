// prog_04_10.cpp
// 2019.05.13

#include <cstdio>


int f(int n)
{
	return n == 0 ? 1: f(n-1) * n;
}


int main()
{
	printf("%d\n", f(5));

	return 0;
}

