// ch17_specialized_library_facilities
// sub_regex.cpp
// 2019/6/17


#include <iostream>
#include <cstdlib>
#include <string>
#include <regex>


bool valid(const std::smatch &smc)
{
	if (smc[1].matched) {
		return smc[3].matched && (smc[4].matched == 0 || smc[4].str() == " ");
	} else {
		return !smc[3].matched && smc[4].str() == smc[6].str();
	}
}


int main()
{
	std::string phone =
			"(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ])?(\\d{4})";
	std::regex re(phone);
	std::smatch smc;
	std::string str;

	while (getline(std::cin, str)) {
		for (std::sregex_iterator it(str.begin(), str.end(), re), end_it; it != end_it; ++it) {
			if (valid(*it)) {
				std::cout << "valid: " << it->str() << std::endl;
			} else {
				std::cout << "not valid: " << it->str() << std::endl;
			}
		}
	}

	return 0;
}
