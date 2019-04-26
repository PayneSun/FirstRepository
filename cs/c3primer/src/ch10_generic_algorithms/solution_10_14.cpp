// ch10_generic_algorithms
// solution_10_14.cpp
// 2019.04.26

#include <iostream>

int main() {
	auto f = [](int a, int b) {return a + b;};

	std::cout << f(2, 3) << std::endl;

	return 0;
}

