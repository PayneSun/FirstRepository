// ch09_sequential_containers
// solution_09_02.cpp
// 2019.04.21

#include <iostream>
#include <deque>
#include <list>

int main()
{
	std::list<std::deque<int>> idList;

	std::deque<int> ideq;
	ideq.push_back(1);
	ideq.push_back(2);

	idList.push_back(ideq);

	for (const auto ele : idList) {
		for (const auto inner : ele) {
			std::cout << inner << std::endl;
		}
	}

	return 0;
}
