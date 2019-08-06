// ch04_expression
// arithmetic_operator.cpp
// 2019/3/31


#include <iostream>


int i = 1024;
int k = -i;
bool b = true;
bool b2 = -b;

int main()
{
	std::cout << "-30 * 3 + 21 / 5 = " << -30 * 3 + 21 / 5 << std::endl;
	std::cout << "-30 + 3 * 21 / 5 = " << -30 + 3 * 21 / 5 << std::endl;
	std::cout << "30 / 3 * 21 % 5 = " << 30 / 3 * 21 % 5 << std::endl;
	std::cout << "-30 / 3 * 21 % 5 = " << -30 / 3 * 21 % 5 << std::endl;

	return 0;
}
