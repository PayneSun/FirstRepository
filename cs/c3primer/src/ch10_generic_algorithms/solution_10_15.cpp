// ch10_generic_algorithms
// solution_10_15.cpp
// 2019.04.26

#include <iostream>

int main() {
	int a = 5;

	auto f = [a](int b) {return a + b;};

	std::cout << f(3) << std::endl;

	return 0;
}

