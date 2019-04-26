// ch10_generic_algorithms
// intro_generic.cpp
// 2019.04.25

#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <iterator>


int main() {
	int ia[] = { 27, 210, 12, 47, 109, 83 };
	int val = 83;

	int* ret = std::find(std::begin(ia), std::end(ia), val);
	std::cout << (ret - ia) << std::endl;

	int sum = std::accumulate(std::begin(ia), std::end(ia), 0);
	std::cout << "Sum of array ia: " << sum << std::endl;

	std::vector<int> ivec(10,0);
	std::fill(ivec.begin(), ivec.end(), 5);
	for (const auto s : ivec) {
		std::cout << "-- " << s;
	}
	std::cout << std::endl;

	std::vector<double> dvec;
	std::fill_n(std::back_inserter(dvec), 10, 1.23);
	for (const auto s : dvec) {
		std::cout << "-- " << s;
	}

	return 0;
}

