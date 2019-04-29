// ch10_generic_algorithms
// iostream_iterator.cpp
// 2019.04.27

#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <iterator>

int main() {
	std::istream_iterator<int> ii_int(std::cin), ii_eof;

	std::cout << std::accumulate(ii_int, ii_eof, 0) << std::endl;

	return 0;
}

