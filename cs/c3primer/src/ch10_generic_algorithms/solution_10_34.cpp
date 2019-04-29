// ch10_generic_algorithms
// solution_10_34.cpp
// 2019.04.29

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

int main()
{
	std::vector<int> ivec;
	for (int i = 0; i != 10; ++i) {
		ivec.push_back(i);
	}

	for (auto itr = ivec.crbegin(); itr != ivec.crend(); ++itr) {
		std::cout << *itr << std::endl;
	}

	return 0;
}

