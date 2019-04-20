// ch08_io_library
// stringstream.cpp
// 2019.04.20

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>


int main(int argc, char *argv[]) {
	struct PersonInfo {
		std::string name;
		std::vector<std::string> phones;
	};

	std::string line, word;
	std::vector<PersonInfo> people;
	while (getline(std::cin, line)) {
		PersonInfo info;

		std::istringstream record(line);
		record >> info.name;
		while (record >> word) {
			info.phones.push_back(word);
		}
		people.push_back(info);
	}




	// example for ostringstream
	for (const auto &entry : people) {
		std::ostringstream formatted, badNums;
		for (const auto &nums : entry.phones) {
			if (!valid(nums)) {
				badNums << " " << nums;
			} else {
				formatted << " " << format(nums);
			}
		}
		if (badNums.str().empty()) {
			std::cout << entry.name << " " << formatted.str() << std::endl;
		} else {
			std::cerr << "input error: " << entry.name
				<< " invalid numbers(s) " << badNums.str() << std::endl;
		}
	}

	return 0;
}
