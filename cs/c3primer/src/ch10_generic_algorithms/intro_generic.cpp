// ch10_generic_algorithms
// intro_generic.cpp
// 2019.04.25

#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>


int main() {

	int ia[] = { 27, 210, 12, 47, 109, 83 };
	int val = 83;

	int* ret = std::find(std::begin(ia), std::end(ia), val);
	std::cout << (ret - ia) << std::endl;

	return 0;
}

