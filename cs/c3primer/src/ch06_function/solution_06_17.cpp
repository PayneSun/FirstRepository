// ch06_function
// solution_06_17.cpp
// 2019/4/8

#include <iostream>
#include <cctype>
#include <sstream>


bool isUpperCase(const std::string &s) {
	for (auto r : s) {
		if (r >= 'A' && r <= 'Z') {
			return true;
		}
	}

	return false;
}


std::string toUpperCase(const std::string &s) {
	std::stringstream rss;

	for (auto r : s) {
		rss << static_cast<char>(toupper(r));
	}

	return rss.str();
}


int main()
{
	std::string str = "helloCpp";
	std::cout << isUpperCase(str) << std::endl;
	std::cout << toUpperCase(str) << std::endl;

	return 0;
}
