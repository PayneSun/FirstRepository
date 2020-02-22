// ch17_specialized_library_facilities
// regex.cpp
// 2019/6/14


#include <iostream>
#include <string>
#include <regex>


int main()
{
	std::string pattern("[^c]ei");
	pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";

	std::regex r(pattern);
	std::smatch result;

	std::string test_str = "receipt freind theif receive";
	if (std::regex_search(test_str, result, r)) {
		std::cout << result.str() << std::endl;
	}

	std::regex re("[[:alnum:]]+\\.(cpp|cxx|cc)$", std::regex::icase);
	std::string filename;
	while (std::cin >> filename) {
		if (std::regex_search(filename, result, re)) {
			std::cout << result.str() << std::endl;
		}
	}

	return 0;
}
