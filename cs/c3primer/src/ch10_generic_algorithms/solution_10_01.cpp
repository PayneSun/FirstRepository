// ch10_generic_algorithms
// solution_10_01.cpp
// 2019.04.25

#include <iostream>
#include <algorithm>
#include <vector>

int main() 
{
	std::vector<int> ivec;
	for (int i = 0; i != 100; ++i) {
		ivec.push_back(i % 10);
	}

	int val = 0, cnt = 0;
	cnt = std::count(ivec.cbegin(), ivec.cend(), val);
	std::cout << val << " occurs: " << cnt << std::endl;

	return 0;
}

