// ch17_specialized_library_facilities
// solution_17_27.cpp
// 2019/6/17


#include <iostream>
#include <string>
#include <regex>


int main()
{
	std::string post_code = "(\\d{5})([-])?(\\d{4})";
	std::regex re(post_code);

	std::string str;
	std::string fmt = "$1-$3";
	while (getline(std::cin, str)) {
		std::cout << std::regex_replace(str, re, fmt) << std::endl;
	}

	return 0;
}
