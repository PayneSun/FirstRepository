// ch10_generic_algorithms
// solution_10_06.cpp
// 2019.04.26

#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

int main()
{
	std::vector<int> ivec;
	for (int i = 0; i != 5; ++i) {
		ivec.push_back(i % 10);
	}

	std::fill_n(ivec.begin(), ivec.size(), 0);
	for (const auto s : ivec) {
		std::cout << s << std::endl;
	}

	return 0;
}

