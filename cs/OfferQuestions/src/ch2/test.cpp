// test.cpp
//
// 2019.08.22

#include <iostream>


int main()
{
	int a = -2147483648;

	std::cout << (a >> 30) << std::endl;
	std::cout << (1 << 30) << std::endl;

	return 0;
}
