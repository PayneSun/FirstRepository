//
// solution_01_02.cpp
// 2019/5/12

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <set>

#define BITSPERWORD 32
#define SHIFT 5
#define MASK 0X1F
#define N 10000000

int a[1 + N/BITSPERWORD];


void set(int i)
{
	a[i >> SHIFT] |= (1 << (i & MASK));
}


void clr(int i)
{
	a[i >> SHIFT] &= ~(1 << (i & MASK));
}


int test(int i)
{
	return a[i >> SHIFT] & (1 << (i & MASK));
}


int main()
{
	//
	return 0;
}

