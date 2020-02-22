// ch17_specialized_library_facilities
// real_random_engine.cpp
// 2019/6/19


#include <iostream>
#include <vector>
#include <random>
#include <cmath>


int main()
{
	std::default_random_engine eng;
	std::uniform_real_distribution<double> urd(0,1);
	for (std::size_t i = 0; i < 10; ++i) {
		std::cout << urd(eng) << " ";
	}
	std::cout << std::endl;

	std::normal_distribution<> nd(4,1.5);
	std::vector<unsigned> vals(9);
	for (std::size_t i = 0; i != 200; ++i) {
		unsigned v = lround(nd(eng));
		if (v < vals.size()) {
			++vals[v];
		}
	}
	for (std::size_t i = 0; i != vals.size(); ++i) {
		std::cout << i << ": " << std::string(vals[i], '*') << std::endl;
	}

	std::string resp;
	std::bernoulli_distribution bd;
	do {
		bool first = bd(eng);
		std::cout << (first ? "We go first" : "You get to go first") << std::endl;
		std::cout << "Play again? Enter 'yes' or 'no'" << std::endl;
	} while (std::cin >> resp && resp[0] == 'y');

	return 0;
}
