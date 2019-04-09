// ch05_statement
// while.cpp
// 2019/4/4


#include <iostream>
#include <vector>

int main()
{
	std::vector<int> ivec;
	int i;
	while (std::cin >> i) {
		ivec.push_back(i);
	}

	auto beg = ivec.begin();
	while (beg != ivec.end() && *beg >= 0) {
		++beg;
	}
	if (beg != ivec.end()) {
		std::cout << "all numbers above zero " << std::endl;
	} else {
		std::cout << "not all numbers above zero " << std::endl;
	}
}
