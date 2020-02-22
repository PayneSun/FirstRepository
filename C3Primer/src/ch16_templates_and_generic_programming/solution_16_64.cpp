// ch16_templates_and_generic_programming
// solution_16_64.cpp
// 2019/6/12


#include <iostream>
#include <vector>
#include <cstring>


template<typename T>
int count(const std::vector<T> &vec, const T& value)
{
	std::cout << "General Template" << std::endl;
	int cnt = 0;
	for (auto it = vec.cbegin(); it != vec.cend(); ++it) {
		if (value == *it) {
			++cnt;
		}
	}

	return cnt;
}


template<>
int count(const std::vector<const char*> &vec, const char* const &pc)
{
	std::cout << "Specialization Template" << std::endl;
	int cnt = 0;
	for (auto it = vec.cbegin(); it != vec.cend(); ++it) {
		if (!strcmp(*it, pc)) {
			++cnt;
		}
	}

	return cnt;
}


int main()
{
	std::vector<const char*> ccvec{"abc", "axbc", "abc", "aybc", "yabc", "defgh", "defgh", "defyh", "defxh"};
	auto pc = "abc";

	std::cout << count(ccvec, pc);

	return 0;
}
