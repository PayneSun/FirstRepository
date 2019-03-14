// ch08_io_library
// ch08_example.cpp
// 2017.04.16

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>


int main(int argc, char *argv[]) {

	std::cout << "Hi!" << std::endl;
	std::cout << "Hi!" << std::flush;
	std::cout << "Hi!" << std::ends;

	std::ifstream input(argv[1]);
	std::ofstream output(argv[0]);

	std::ofstream out("file", std::ofstream::out);
	std::ofstream out2("file2", std::ofstream::app);

	// example for istringstream
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
