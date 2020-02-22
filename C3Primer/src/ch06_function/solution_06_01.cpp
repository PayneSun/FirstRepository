// ch06_function
// solution_06_01.cpp
// 2019/4/7

#include <iostream>


void fact()
{
	int val;
	while (std::cin >> val) {
		int ret = 1;
		while (val > 1) {
			ret *= val--;
		}
		std::cout << ret << std::endl;
	}
}


int main()
{
	fact();
}
