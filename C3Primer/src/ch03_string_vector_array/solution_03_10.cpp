// ch03_string_vector_array
// solution_03_10.cpp
// 2019/3/26


#include <iostream>
#include <string>
#include <cctype>

int main()
{
	std::string str;
	getline(std::cin, str);

	for (auto &c : str) {
		if (!ispunct(c)) {
			std::cout << c;
		}
	}
	std::cout << std::endl;
	return 0;
}
