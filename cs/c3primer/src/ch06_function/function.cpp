// ch06_function
// function.cpp
// 2019/4/7

#include <iostream>


int fact(int val)
{
	int ret = 1;
	while (val > 1) {
		ret *= val--;
	}
	return ret;
}


int main()
{
	std::cout << fact(5) << std::endl;

	return 0;
}

