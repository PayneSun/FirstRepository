// ch17_specialized_library_facilities
// solution_17_28.cpp
// 2019/6/18


#include <iostream>
#include <string>
#include <random>


int main()
{
	std::default_random_engine dre;
	std::uniform_int_distribution<unsigned int> ui;

	for (std::size_t i = 0; i < 5; ++i) {
		std::cout << ui(dre) << std::endl;
	}

	return 0;
}
