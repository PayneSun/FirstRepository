// ch17_specialized_library_facilities
// regex_replace.cpp
// 2019/6/17


#include <iostream>
#include <string>
#include <regex>


int main()
{
	std::string phone =
			"(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ])?(\\d{4})";
	std::regex re(phone);

	std::string str;
	std::string fmt = "$2.$5.$7";

	while (getline(std::cin, str)) {
		std::cout << std::regex_replace(str, re, fmt) << std::endl;
		std::cout << std::regex_replace(str, re, fmt, std::regex_constants::format_no_copy) << std::endl;
	}

	return 0;
}
