// ch05_statment
// solution_05_17.cpp
// 2019/4/4


#include <iostream>
#include <vector>

int main()
{
	std::vector<int> ivec1 = {0, 1, 1, 2};
	std::vector<int> ivec2 = {0, 1, 2, 2, 3, 5, 8};

	decltype(ivec1.size()) i = 0;
	while (i < ivec1.size() && i < ivec2.size()) {
		if (ivec1[i] != ivec2[i]) {
			std::cout << "no" << std::endl;
			return 0;
		}
		++i;
	}

	if (i == ivec1.size() || i == ivec2.size()) {
		std::cout << "ok" << std::endl;
	} else {
		std::cout << "no" << std::endl;
	}

	return 0;
}
