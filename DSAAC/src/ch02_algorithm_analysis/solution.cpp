/**
 * ch_02_algorithm_analysis/solution.cpp
 *
 * 2020.03.31
 */

#include <iostream>

//Question 2.16
long long pow(long long x, unsigned int n) {
	long long ret = 1;
	if (!n) {
		return ret;
	}

	while (n) {
		if (n & 1) {
			ret *= x;
		}
		x *= x;
		n >>= 1;
	}

	return ret;
}

int main() {
	std::cout << pow(2, 0) << std::endl;
	std::cout << pow(2, 1) << std::endl;
	std::cout << pow(2, 5) << std::endl;
	std::cout << pow(2, 10) << std::endl;

	return 0;
}
