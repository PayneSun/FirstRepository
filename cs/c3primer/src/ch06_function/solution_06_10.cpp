// ch06_function
// solution_06_10.cpp
// 2019/4/8

#include <iostream>


void swap(int *lval, int *rval)
{
	*lval = *lval + *rval;
	*rval = *lval - *rval;
	*lval = *lval - *rval;
}


int main()
{
	int a = 2, b = 3;
	std::cout << "a = " << a << ", b = " << b << std::endl;

	swap(&a, &b);
	std::cout << "a = " << a << ", b = " << b << std::endl;

	return 0;
}
