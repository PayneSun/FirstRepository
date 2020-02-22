// ch09_sequential_containers
// solution_09_18.cpp
// 2019.04.23

#include <iostream>
#include <string>
#include <deque>

int main()
{
	std::deque<std::string> sdeq;

	std::string instr;
	while (std::cin >> instr) {
		sdeq.push_back(instr);
	}

	for (auto itr = sdeq.cbegin(); itr != sdeq.cend(); ++itr) {
		std::cout << "--*-- " << *itr << std::endl;
	}

	return 0;
}
