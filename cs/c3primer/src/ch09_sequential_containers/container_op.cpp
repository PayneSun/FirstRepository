// ch09_sequential_containers
// container_op.cpp
// 2019.04.23

#include <iostream>
#include <string>
#include <array>
#include <list>
#include <vector>
#include <forward_list>


int main() {

	std::vector<std::string> svec;

	svec.insert(svec.begin(), "world");
	for (const auto cstr : svec) {
		std::cout << cstr << " ";
	}
	std::cout << "\n--*--" << std::endl;

	svec.insert(svec.end(), 10, "sun");
	for (const auto cstr : svec) {
		std::cout << cstr << " ";
	}
	std::cout << "\n--*--" << std::endl;

	std::list<std::string> slist;

	slist.insert(slist.begin(), "hello");
	for (const auto cstr : slist) {
		std::cout << cstr << " ";
	}
	std::cout << "\n--*--" << std::endl;

	slist.insert(slist.end(), {"one", "two", "three", "four"});
	for (const auto cstr : slist) {
		std::cout << cstr << " ";
	}
	std::cout << "\n--*--" << std::endl;

	std::list<int> ilist(10, 42);
	ilist.resize(15);
	ilist.resize(25, -1);
	ilist.resize(5);



	return 0;
}
