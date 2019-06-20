// ch17_specialized_library_facilities
// solution_17_37.cpp
// 2019/6/20


#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdlib>


int main()
{
	std::ifstream ifs("text.txt");
	char buffer[256];

	while (ifs.get() != EOF) {
		ifs.getline(buffer, 256);
		std::stringstream ss(buffer);
		std::string str;
		while (ss >> str) {
			std::cout << str << std::endl;
		}
	}

	return 0;
}
