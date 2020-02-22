// ch17_specialized_library_facilities
// solution_17_23.cpp
// 2019/6/17


#include <iostream>
#include <cstdlib>
#include <string>
#include <regex>


int main()
{
	std::string post_code = "(\\d{5})([-])?(\\d{4})?";
	std::regex re(post_code);

	std::string tstr;
	while (getline(std::cin, tstr)) {
		for (std::sregex_iterator it(tstr.begin(), tstr.end(), re), end_it; it != end_it; ++it) {
			if ((*it)[2].matched == (*it)[3].matched) {
				std::cout << it->str() << std::endl;
			}
		}
	}

	return 0;
}
