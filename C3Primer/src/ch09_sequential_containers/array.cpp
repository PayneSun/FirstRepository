// ch09_sequential_containers
// array.cpp
// 2019.04.18

#include <iostream>
#include <string>
#include <array>
#include <list>
#include <vector>
#include <forward_list>


int main() {
	std::array<int, 42> arr = {0};
	std::array<std::string, 10> sarr;

	std::list<std::string> slist(1);
	slist.assign(10, "Hi!");
	for (const auto cstr : slist) {
		std::cout << cstr << std::endl;
	}

	return 0;
}
