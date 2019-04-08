// ch06_function
// solution_06_33.cpp
// 2019/4/8

#include <iostream>
#include <vector>


void printVec(std::vector<int> &ivec) {
	if (ivec.size() < 1) {
		return;
	}

	std::cout << ivec[0];
	std::vector<int> nvec(ivec.begin() + 1, ivec.end());
	printVec(nvec);
}


int main()
{
	std::vector<int> ivec = {1, 3, 5, 7, 9};

	printVec(ivec);

	return 0;
}
