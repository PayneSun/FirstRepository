// ch08_io_library
// cache.cpp
// 2019.04.19

#include <iostream>

int main(int argc, char *argv[]) {
	std::cout << "Hi!" << std::endl;
	std::cout << "Hi!" << std::flush;
	std::cout << "Hi!" << std::ends;

	return 0;
}
