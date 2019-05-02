// ch11_associative_containers
// solution_11_09.cpp
// 2019.05.02

#include <iostream>
#include <string>
#include <list>
#include <map>


int main()
{
	std::map<std::string, std::list<int>> slmap;

	slmap["hello"] = std::list<int>{1, 2, 3};
	slmap["world"] = std::list<int>{4, 5, 6};
	for (const auto ele : slmap) {
		std::cout << ele.first << "\t";
		for (const auto il : ele.second) {
			std::cout << il << " - ";
		}
		std::cout << std::endl;
	}

	return 0;
}
