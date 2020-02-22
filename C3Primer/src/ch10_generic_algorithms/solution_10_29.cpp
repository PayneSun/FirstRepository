// ch10_generic_algorithms
// solution_10_29.cpp
// 2019.04.27

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <iterator>

int main()
{
	std::ifstream ifs("word_list.txt");
	std::istream_iterator<std::string> iitr(ifs), ieof;

	std::vector<std::string> svec;
	while (iitr != ieof) {
		svec.push_back(*iitr++);
	}

	for (const auto str : svec) {
		std::cout << str << std::endl;
	}

	return 0;
}

