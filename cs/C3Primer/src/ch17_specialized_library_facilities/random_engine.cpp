// ch17_specialized_library_facilities
// random_engine.cpp
// 2019/6/17


#include <iostream>
#include <vector>
#include <list>
#include <random>


std::vector<unsigned> randVec()
{
	static std::default_random_engine eng;
	static std::uniform_int_distribution<unsigned> u(0,9);
	std::vector<unsigned> ret;
	for (std::size_t i = 0; i < 5; ++i) {
		ret.push_back(u(eng));
	}

	return ret;
}


int main()
{
	std::default_random_engine e;
	for (std::size_t i = 0; i < 10; ++i) {
		std::cout << e() << " ";
	}
	std::cout << std::endl;

	std::uniform_int_distribution<unsigned> u(0,9);
	std::default_random_engine eng;
	for (std::size_t i = 0; i < 10; ++ i) {
		std::cout << u(eng) << " ";
	}
	std::cout << std::endl;

	std::vector<unsigned> v1(randVec());
	for (auto it = v1.cbegin(); it != v1.cend(); ++it) {
		std::cout << *it << "-";
	}
	std::cout << std::endl;

	std::vector<unsigned> v2(randVec());
	for (auto it = v2.cbegin(); it != v2.cend(); ++it) {
		std::cout << *it << "-";
	}
	std::cout << std::endl;


	return 0;
}


