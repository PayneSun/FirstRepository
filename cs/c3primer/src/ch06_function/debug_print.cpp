// ch06_function
// debug_print.cpp
// 2019/4/10


#include <iostream>
#include <cassert>

//#define NDEBUG


void print(const int ia[], std::size_t size)
{
#ifdef NDEBUG
	std::cerr << __func__ << ": array size is " << size << std::endl;
#else
	for (std::size_t i = 0; i < size; ++i) {
		std::cout << ia[i] << std::endl;
	}
#endif
}


int main()
{
	int ia[5] = {1, 3, 5, 7, 9};

	print(ia, std::end(ia) - std::begin(ia));

	return 0;
}
