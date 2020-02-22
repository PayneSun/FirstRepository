// ch01_begin
// solution_01_09.cpp
// 2019/3/21

#include <iostream>

int main()
{
	int sum = 0, val = 50;
	while (val <= 100) {
		sum += val;
		++val;
	}
	std::cout << "Sum of 50 to 100 inclusive is "
			<< sum << std::endl;
	return 0;
}
