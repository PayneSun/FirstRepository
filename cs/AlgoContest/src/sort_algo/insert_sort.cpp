//
// insert_sort.cpp

#include <iostream>
#include <vector>
#include <algorithm>

void insertSort(std::vector<int> &ivec)
{
	for (std::size_t i = 1; i < ivec.size(); ++i) {
		for (std::size_t j = i - 1; j >= 0; --j) {
			if (ivec[j] > ivec[i]) {
				int tmp = ivec[i];
				ivec[i] = ivec[j];
				ivec[j] = tmp;
			}
		}
	}
}


int main()
{
	std::vector<int> ivec{9, 7, 5, 3, 1};
	for (auto it = ivec.begin(); it != ivec.end(); ++it) {
		std::cout << *it;
	}

	insertSort(ivec);

	for (auto i = 0; i < ivec.size(); ++i) {
		std::cout << ivec[i];
	}

	return 0;
}
