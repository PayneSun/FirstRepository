// ch03_string_vector_array
// solution_03_06.cpp
// 2019/3/26


#include <iostream>
#include <string>

int main()
{
	std::string str;
	std::cin >> str;
	for (auto &rc : str) {
		rc = 'X';
	}
	std::cout << str << std::endl;
	return 0;
}
