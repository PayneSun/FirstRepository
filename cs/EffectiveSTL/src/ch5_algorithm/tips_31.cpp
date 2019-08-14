// 第31条：了解各种与排序有关的选择
// tips_31.cpp
//
// 2019/8/14

#include <iostream>
#include <vector>
#include <algorithm>


int main()
{
	std::vector<int> ivec;
	for (int i = 0; i < 10; i++) {
		ivec.push_back((5 * i + 1) % 11);
	}
	for (auto r: ivec) { std::cout << r << " ";	}
	std::cout << std::endl;

//	std::partition(ivec.begin(), ivec.end(), [](int x) { return x < 5; });
//	std::stable_partition(ivec.begin(), ivec.end(), [](int x) { return x < 5; });
//	std::nth_element(ivec.begin(), ivec.begin() + 5, ivec.end());
//	std::partial_sort(ivec.begin(), ivec.begin() + 5, ivec.end());
//	std::sort(ivec.begin(), ivec.end());
//	std::stable_sort(ivec.begin(), ivec.end());
//	for (auto r: ivec) { std::cout << r << " ";	}
//	std::cout << std::endl;

	return 0;
}

