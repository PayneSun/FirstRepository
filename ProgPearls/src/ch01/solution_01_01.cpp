//
// solution_01_01.cpp
// 2019/5/12

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <set>

#define MAX_LEN 100000

int a[MAX_LEN];



int intcomp(const void *x, const void *y)
{
	return (*(int*)x - *(int*)y);
}


void c_sort()
{
	int i, n = 0;
	while (scanf("%d", &a[n++]) != EOF) { }

	qsort(a, n, sizeof(int), intcomp);
	for (i = 0; i < n; ++i) {
		printf("%d\n", a[i]);
	}
}


void cpp_sort()
{
	int i;
	std::set<int> s;
	while (std::cin >> i) {
		s.insert(i);
	}

	std::set<int>::iterator j;
	for (j = s.begin(); j != s.end(); ++j) {
		std::cout << *j << std::endl;
	}
}


int main()
{
//	c_sort();
	cpp_sort();

	return 0;
}

