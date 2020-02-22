// ch08_io_library
// solution_08_04.cpp
// 2019.04.19

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>

int main(int argc, char *argv[]) {
	std::ifstream ifs("word_list.txt");

	std::string lstr;
	std::vector<std::string> svec;
	while (getline(ifs, lstr)) {
		svec.push_back(lstr);
	}

	for (auto str : svec) {
		std::cout << str << std::endl;
	}

	return 0;
}
