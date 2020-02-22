// ch10_generic_algorithms
// custom_op.cpp
// 2019.04.26

#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <iterator>
#include <string>

bool isShorter(const std::string &s1, const std::string &s2) 
{
	return s1.size() < s2.size();
}

int main()
{
	std::vector<std::string> svec { "welcome", "to", "china", "or" };

	std::sort(svec.begin(), svec.end(), isShorter);
	for (const auto str : svec) {
		std::cout << str << std::endl;
	}

	std::stable_sort(svec.begin(), svec.end(), isShorter);
	for (const auto str : svec) {
		std::cout << str << std::endl;
	}

	return 0;
}

