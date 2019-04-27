// ch10_generic_algorithms
// solution_10_20.cpp
// 2019.04.26

#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <vector>

using namespace std::placeholders;

bool isShorter(const std::string &str) {
	return str.size() <= 6;
}


int main() {
	std::vector<std::string> svec{"welcome", "to", "Australia"};

	auto ret = std::count_if(svec.begin(), svec.end(),
			std::bind(isShorter, _1));

	std::cout << ret << std::endl;

	return 0;
}

