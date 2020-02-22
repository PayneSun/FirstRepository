// ch17_specialized_library_facilities
// solution_17_10.cpp
// 2019/6/14


#include <iostream>
#include <vector>
#include <string>
#include <bitset>


int main()
{
	std::vector<int> ivec{1,2,5,8,13,21};

	std::bitset<32> bit;
	for (auto it = ivec.cbegin(); it != ivec.cend(); ++it) {
		bit.set(*it);
	}

	std::cout << bit.count() << std::endl;
	std::cout << bit.to_string() << std::endl;

	return 0;
}
