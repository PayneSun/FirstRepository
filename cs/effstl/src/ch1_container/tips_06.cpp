// 第6条：当心C++编译器最烦人的分析机制
// tips_06.cpp
// 2019/5/26


#include <iostream>
#include <list>
#include <fstream>
#include <iterator>


int main()
{
	std::ifstream dataFile("ints.data");
	std::istream_iterator<int> dataBegin(dataFile);
	std::istream_iterator<int> dataEnd;
	std::list<int> data(dataBegin, dataEnd);

	for (const auto ele : data) {
		std::cout << ele << std::endl;
	}

	return 0;
}
