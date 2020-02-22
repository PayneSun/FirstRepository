// ch04_expression
// solution_04_36.cpp
// 2019/4/3


#include <iostream>


int main()
{
	int i = 5;
	double d = 7.3;

	i *= static_cast<int>(d);
	std::cout << i << std::endl;

	return 0;
}
