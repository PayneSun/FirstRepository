// ch06_function
// solution_06_24.cpp
// 2019/4/8

#include <iostream>


void print(const int ia[10]) {
	for (std::size_t i = 0; i != 10; ++i) {
		std::cout << ia[i] << std::endl;
	}
}


int main()
{
	int ia[5] = {0};
	print(ia);

	return 0;
}
