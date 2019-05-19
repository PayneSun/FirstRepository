// ch04_expression
// solution_04_21.cpp
// 2019/4/1


#include <iostream>
#include <vector>


int main()
{
	std::vector<int> ivec;
	for (int i = 0; i < 10; ++i) {
		ivec.push_back(i+1);
	}
	for (auto r : ivec) {
		std::cout << r << " ";
	}
	std::cout << std::endl;

	for (std::size_t i = 0; i < ivec.size(); ++i) {
		int tmp = ivec[i];
		ivec[i] = (tmp % 2) ? (tmp * 2) : tmp;
	}
	for (auto r : ivec) {
		std::cout << r << " ";
	}

	return 0;
}
