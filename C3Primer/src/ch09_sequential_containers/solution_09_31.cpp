// ch09_sequential_containers
// solution_09_31.cpp
// 2019.04.24

#include <iostream>
#include <string>
#include <list>
#include <forward_list>


int main() {
	std::list<int> il = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	auto iter = il.begin();
	while (iter != il.end()) {
		if (*iter % 2) {
			iter = il.insert(iter, *iter++);
			++iter;
		} else {
			iter = il.erase(iter);
		}
	}

	for (const auto ci : il) {
		std::cout << ci << std::endl;
	}

	return 0;
}
