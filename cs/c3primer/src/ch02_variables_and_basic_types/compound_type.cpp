// ch02_variables_and_basic_types
// compound_type.cpp
//
// 2019/3/14


#include <iostream>
#include <cstdlib>

int ival = 1024;
int &refVal = ival;
int &refVal2 = refVal;

int main()
{
	int i = 0, &r1 = i;
	double d = 0, &r2 = d;
	r2 = 3.14159;
	r2 = r1;
	i = r2;
	r1 = d;

	i = 5;
	r1 = 10;
	std::cout << i << " " << r1 << std::endl;

	int *p1 = nullptr;
	int *p2 = 0;
	int *p3 = NULL;

	int ival = 0;
//	double *dp = &ival;
//	int *ip = ival;
	int *p = &ival;

	//指向指针的引用
	int iVal2 = 42;
	int *pVal;
	int *&rip = pVal;
	rip = &i;
	*rip = 0;

	return 0;
}
