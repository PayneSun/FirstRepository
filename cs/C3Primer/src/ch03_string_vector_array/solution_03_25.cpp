// ch03_string_vector_array
// solution_03_25.cpp
// 2019/3/27


#include <iostream>
#include <vector>


int main()
{
	std::vector<int> ivec(11, 0);

	int grade;
	auto it = ivec.begin();
	while (std::cin >> grade) {
		*(it + grade / 10) += 1;
	}

	for (auto it = ivec.cbegin(); it != ivec.cend(); ++it) {
		std::cout << *it << std::endl;
	}

	return 0;
}
