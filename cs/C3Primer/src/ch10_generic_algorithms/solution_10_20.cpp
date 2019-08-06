// ch10_generic_algorithms
// solution_10_20.cpp
// 2019.04.26

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

int main()
{
	std::vector<std::string> svec { "welcome", "to", "chinaxxx" };

	auto ret = std::count_if(svec.begin(), svec.end(),
			[](const std::string &str) {return str.size() > 6;});
	std::cout << ret << std::endl;

	return 0;
}

