// ch01_begin
// solution_01_11.cpp
// 2019/3/21

#include <iostream>

int main()
{
	int val1, val2;
	std::cin >> val1 >> val2;

	if (val1 <= val2) {
		while (val1 <= val2) {
			std::cout << val1 << std::endl;
			++val1;
		}
	} else {
		while (val1 >= val2) {
			std::cout << val1 << std::endl;
			--val1;
		}
	}
	return 0;
}
