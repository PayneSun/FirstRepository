// ch16_templates_and_generic_programming
// solution_16_19.cpp
// 2019/6/8


#include <iostream>
#include <vector>


template<typename T>
void printElement(const T& container)
{
	typename T::size_type st = 0;
	for (; st < container.size(); ++st) {
		std::cout << container[st] << std::endl;
	}
}


int main()
{
	std::vector<int> ivec{2,4,6,8};
	printElement(ivec);

	return 0;
}
