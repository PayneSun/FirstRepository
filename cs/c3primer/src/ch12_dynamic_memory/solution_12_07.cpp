// ch12_dynamic_memory
// solution_12_07.cpp
// 2019.05.09

#include <iostream>
#include <memory>
#include <vector>


std::shared_ptr<std::vector<int>> getVec()
{
	return std::make_shared<std::vector<int>>();
}


void inputVec(std::shared_ptr<std::vector<int>> ps)
{
	auto pVec = ps.get();
	int val;
	while (std::cin >> val) {
		pVec->push_back(val);
	}
}


void printVec(std::shared_ptr<std::vector<int>> ps)
{
	auto pVec = ps.get();
	for (auto it = pVec->cbegin(); it != pVec->cend(); ++it) {
		std::cout << *it << std::endl;
	}
}


int main()
{
	auto pVec = getVec();

	inputVec(pVec);
	printVec(pVec);

	return 0;
}
