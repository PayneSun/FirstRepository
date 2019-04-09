// ch03_string_vector_array
// solution_03_14.cpp
// 2019/3/27


#include <iostream>
#include <string>
#include <vector>


int main()
{
	int ival;
	std::vector<int> ivec;
	while (std::cin >> ival) {
		ivec.push_back(ival);
	}
	std::cout << ivec.size() << std::endl;

	return 0;
}
