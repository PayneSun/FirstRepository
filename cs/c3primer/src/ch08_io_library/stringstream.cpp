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

	for (const auto &entry : people) {
		std::ostringstream oss;
		for (const auto &nums : entry.phones) {
			oss << " " << nums;
		}
	}

	return 0;
}
