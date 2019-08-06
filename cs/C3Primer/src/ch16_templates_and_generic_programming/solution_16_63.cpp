// ch16_templates_and_generic_programming
// solution_16_63.cpp
// 2019/6/12


#include <iostream>
#include <vector>


template<typename T>
int count(const std::vector<T> &vec, const T& value)
{
	int cnt = 0;
	for (auto it = vec.cbegin(); it != vec.cend(); ++it) {
		if (value == *it) {
			++cnt;
		}
	}

	return cnt;
}


int main()
{
	std::vector<int> ivec{2,4,6,8,4,6,8,4,6,8,4,6,8,4,6,8,4,6,8,4,6,8};

	std::cout << count(ivec, 6);

	return 0;
}
