// ch03_string_vector_array
// solution_03_23.cpp
// 2019/3/27


#include <iostream>
#include <vector>


int main()
{
	std::vector<int> ivec(10, 11);

	for (auto it = ivec.begin(); it != ivec.end(); ++it) {
		*it *= 2;
	}

	for (auto it = ivec.cbegin(); it != ivec.cend(); ++it) {
		std::cout << *it << std::endl;
	}

	return 0;
}
