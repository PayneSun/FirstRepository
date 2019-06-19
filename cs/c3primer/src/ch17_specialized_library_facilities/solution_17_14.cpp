// ch17_specialized_library_facilities
// solution_17_14.cpp
// 2019/6/17


#include <iostream>
#include <string>
#include <regex>


int main()
{
	std::string pattern("[^c]ei");
	pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";

	std::regex r(pattern);

	std::smatch sret;
	std::string tstr = "receipt freind theif receive";
	if (std::regex_search(tstr, sret, r)) {
		std::cout << sret.str() << std::endl;
	}

	auto pc = "receipt freind theif receive";
	std::cmatch cret;
//	if (std::regex_search(pc, sret, r)) {
//		std::cout << sret.str() << std::endl;
//	}

	if (std::regex_search(pc, cret, r)) {
		std::cout << sret.str() << std::endl;
	}

	return 0;
}

