// ch01_begin
// variable_number_input.cpp
// 2019/3/21

#include <iostream>

int main()
{
	int sum = 0, value = 0;
	while (std::cin >> value) {
		sum += value;
	}
	std::cout << "Sum is: " << sum << std::endl;
	return 0;
}
