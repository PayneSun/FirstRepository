// ch09_sequential_containers
// solution_09_20.cpp
// 2019.04.23

#include <iostream>
#include <deque>
#include <list>

int main()
{
	std::list<int> ilist;
	for (int i = 0; i < 10; ++i) {
		ilist.push_back(i);
	}

	std::deque<int> odeq, edeq;
	for (auto ele : ilist) {
		if (ele % 2) {
			odeq.push_back(ele);
		} else {
			edeq.push_back(ele);
		}
	}

	for (const auto ci : odeq) {
		std::cout << ci << " ";
	}
	std::cout << "--*--" << std::endl;

	for (const auto ci : edeq) {
		std::cout << ci << " ";
	}
	std::cout << "--*--" << std::endl;

	return 0;
}
