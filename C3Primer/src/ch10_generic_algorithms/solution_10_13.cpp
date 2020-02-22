// ch10_generic_algorithms
// solution_10_13.cpp
// 2019.04.26

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

bool isLength(const std::string &str)
{
	return str.size() == 5;
}

int main()
{
	std::vector<std::string> svec { "welcome", "to", "China", "and", "Japan" };

	auto ret = std::partition(svec.begin(), svec.end(), isLength);
	for (auto itr = svec.begin(); itr != ret; ++itr) {
		std::cout << *itr << std::endl;
	}

	return 0;
}

