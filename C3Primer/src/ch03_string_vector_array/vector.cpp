// ch03_string_vector_array
// vector.cpp
// 2019/3/28


#include <iostream>
#include <iterator>


int main()
{
	int ia[] = {11, 22, 33};
	int *beg = std::begin(ia);
	int *last = std::end(ia);

	for (; beg != last; beg++) {
		std::cout << *beg << std::endl;
	}
}
