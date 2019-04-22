// ch09_sequential_containers
// solution_09_14.cpp
// 2019.04.22

#include <iostream>
#include <vector>
#include <list>

int main()
{
	std::list<const char *> clist = {"made", "in", "china"};

	std::vector<std::string> svec1(clist.begin(), clist.end());
	for (const auto ele : svec1) {
		std::cout << ele << std::endl;
	}

	return 0;
}
