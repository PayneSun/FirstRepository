// ch08_io_library
// solution_08_08.cpp
// 2017.04.20

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>

int main(int argc, char *argv[]) {
	std::ofstream ofs("word_list.txt", std::ofstream::app);

	std::string ostr = "yyyXXX";
	ofs.write(ostr.c_str(), ostr.size());
	ofs.close();

	return 0;
}
