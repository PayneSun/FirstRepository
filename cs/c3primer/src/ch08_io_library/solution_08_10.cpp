// ch08_io_library
// solution_08_10.cpp
// 2019.04.20

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

int main(int argc, char *argv[])
{
	std::ifstream ifs("word_list.txt", std::ofstream::in);

	std::string line, word;
	std::vector<std::string> svec;
	while (getline(ifs, line)) {
		std::istringstream iss(line);
		while (iss >> word) {
			svec.push_back(word);
		}
	}

	for (auto word : svec) {
		std::cout << word << std::endl;
	}

	return 0;
}
