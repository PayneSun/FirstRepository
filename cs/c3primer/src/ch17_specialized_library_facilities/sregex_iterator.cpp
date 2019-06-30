// ch17_specialized_library_facilities
// sregex_iterator.cpp
// 2019/6/17


#include <iostream>
#include <string>
#include <regex>


int main()
{
	std::string pattern("[^c]ei");
	pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";

	std::regex re(pattern, std::regex::icase);
	std::string tstr = "receipt freind theif receive";
	for (std::sregex_iterator it(tstr.begin(), tstr.end(), re), end_it; it != end_it; ++it) {
		std::cout << it->str() << std::endl;
	}

	for (std::sregex_iterator it(tstr.begin(), tstr.end(), re), end_it; it != end_it; ++it) {
		auto pos = it->prefix().str().length();
		pos = pos > 5 ? pos - 5 : 0;
		std::cout << it->prefix().str().substr(pos) << "\n\t\t>>>" << it->str()
				<< " <<<\n" << it->suffix().str().substr(0,5) << std::endl;
	}

	return 0;
}
