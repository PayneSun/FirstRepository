// ch09_sequential_containers
// solution_09_26.cpp
// 2019.04.23

#include <iostream>
#include <vector>
#include <list>

int main()
{
	int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 54, 89};

	std::vector<int> ivec(std::begin(ia), std::end(ia));
	std::list<int> ilist(std::begin(ia), std::end(ia));

	auto itl = ilist.begin();
	while (itl != ilist.end()) {
		if (*itl % 2) {
			itl = ilist.erase(itl);
		} else {
			itl++;
		}
	}
	for (const auto ci : ilist) {
		std::cout << ci << " ";
	}
	std::cout << "--*--" << std::endl;

	auto itv = ivec.begin();
	while (itv != ivec.end()) {
		if (*itv % 2) {
			itv++;
		} else {
			itv = ivec.erase(itv);
		}
	}
	for (const auto ci : ivec) {
		std::cout << ci << " ";
	}
	std::cout << "--*--" << std::endl;

	return 0;
}
