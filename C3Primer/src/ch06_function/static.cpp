// ch06_function
// static.cpp
// 2019/4/7

#include <iostream>

std::size_t count_calls()
{
	static std::size_t ctr = 0;
	return ++ctr;
}


int main()
{
	for (std::size_t i = 0; i < 10; ++i) {
		std::cout << count_calls() << std::endl;
	}

	return 0;
}
