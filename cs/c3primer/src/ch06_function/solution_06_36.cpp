// ch06_function
// solution_06_36.cpp
// 2019/4/9

#include <iostream>
#include <string>


std::string sarr[10];

std::string (*func(const std::string &s))[10] {
	for (std::size_t i = 0; i < 10; ++i) {
		sarr[i] = s;
	}

	return &sarr;
}

int main()
{
	auto *psarr = func("cpp");

	for (auto it = std::begin(*psarr); it != std::end(*psarr); ++it) {
		std::cout << *it << std::endl;
	}

	return 0;
}
