// ch09_sequential_containers
// solution_09_27.cpp
// 2019.04.23

#include <iostream>
#include <forward_list>

int main() {
	std::forward_list<int> flst = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	auto prev = flst.before_begin();
	auto curr = flst.begin();

	while (curr != flst.end()) {
		if (*curr % 2 == 0) {
			curr = flst.erase_after(prev);
		} else {
			prev = curr;
			++curr;
		}
	}

	for (const auto ci : flst) {
		std::cout << ci << " ";
	}
	std::cout << "--*--" << std::endl;

	return 0;
}
