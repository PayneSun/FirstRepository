// ch12_dynamic_memory
// solution_12_06.cpp
// 2019.05.09

#include <iostream>
#include <memory>
#include <list>
#include <vector>

using namespace std;


std::vector<int>* getVec()
{
	return new std::vector<int>();
}


void inputVec(std::vector<int> *pVec)
{
	int val;
	while (std::cin >> val) {
		pVec->push_back(val);
	}
}


void printVec(std::vector<int> *pVec)
{
	for (auto it = pVec->cbegin(); it != pVec->cend(); ++it) {
		std::cout << *it << std::endl;
	}

	delete pVec;
}


int main()
{
	auto p1 = getVec();

	inputVec(p1);
	printVec(p1);

	return 0;
}
