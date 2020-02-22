// ch16_templates_and_generic_programming
// solution_16_20.cpp
// 2019/6/8


#include <iostream>
#include <vector>


template<typename T>
void printElement(const T& container)
{
	typename T::const_iterator it = container.begin();
	for (; it != container.end(); ++it) {
		std::cout << *it << std::endl;
	}
}


int main()
{
	std::vector<int> ivec{2,4,6,8};
	printElement(ivec);

	return 0;
}
