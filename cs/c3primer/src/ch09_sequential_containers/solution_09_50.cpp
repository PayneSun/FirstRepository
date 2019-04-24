// ch09_sequential_containers
// solution_09_50.cpp
// 2019.04.24

#include <iostream>
#include <string>
#include <vector>


int main() {
	std::vector<std::string> svec = {
			"12", "33", "46", "67", "74", "81", "53", "96"};

	double sum = 0.0;
	for (const auto cstr : svec) {
		sum += std::stod(cstr);
	}
	std::cout << sum << std::endl;

	return 0;
}
