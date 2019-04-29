// ch10_generic_algorithms
// solution_10_26.cpp
// 2019.04.26

#include <iostream>
#include <algorithm>
#include <list>

int main() {
	std::list<int> il1 { 1, 2, 3, 4, 5, 5 };

	std::list<int> il2, il3;
	std::unique_copy(il1.begin(), il1.end(), std::front_inserter(il2));
	std::unique_copy(il1.begin(), il1.end(), std::back_inserter(il3));

	for (const auto ir : il2) {
		std::cout << ir << " - ";
	}
	std::cout << std::endl;

	for (const auto ir : il3) {
		std::cout << ir << " - ";
	}
	std::cout << std::endl;

	return 0;
}

