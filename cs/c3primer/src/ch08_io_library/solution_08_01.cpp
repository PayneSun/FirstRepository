// ch08_io_library
// solution_08_01.cpp
// 2019.04.18

#include <iostream>

std::istream& func(std::istream &is) {
	auto oldState = is.rdstate();

	int tmp;
	while (is >> tmp) {
		std::cout << "Output: " << tmp << std::endl;
	}

	is.setstate(oldState);

	return is;
}

int main(int argc, char *argv[]) {
	func(std::cin);

	return 0;
}
