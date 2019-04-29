// ch10_generic_algorithms
// custom_op.cpp
// 2019.04.26

#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <iterator>
#include <string>

int main() 
{
	auto f = []() -> int {return 42;};
	std::cout << f() << std::endl;

	int sz = 3;
	std::vector<std::string> svec { "welcome", "to", "China", "and", "Japan" };
	auto wc = std::partition(svec.begin(), svec.end(),
			[sz](const std::string &str) {return str.size() >= sz;});

	for (auto itr = svec.begin(); itr != wc; ++itr) {
		std::cout << *itr << " - ";
	}
	std::cout << std::endl;

	std::for_each(svec.begin(), svec.end(),
			[svec](decltype(svec)::value_type val) {std::cout << val << std::endl;});

	auto fn = [sz]() mutable {return ++sz;};
	int rt = fn();
	std::cout << rt << std::endl;

	return 0;
}

