// ch06_function
// solution_06_27.cpp
// 2019/4/8

#include <iostream>
#include <initializer_list>

int sum(std::initializer_list<int> il) {
	int ret = 0;
//	for (auto it = il.begin(); it != il.end(); ++it) {
//		ret += *it;
//	}
	for (auto r : il) {
		ret += r;
	}

	return ret;
}


int main()
{
	std::cout << sum({1, 2, 3}) << std::endl;
	std::cout << sum({1, 3, 5, 7}) << std::endl;

	return 0;
}
