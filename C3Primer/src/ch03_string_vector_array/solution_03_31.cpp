// ch03_string_vector_array
// solution_03_31.cpp
// 2019/3/27


#include <iostream>


int main()
{
	int arr[10] = {};

	for (std::size_t i = 0; i < 10; ++i) {
		arr[i] = i;
	}

	for (std::size_t i = 0; i < 10; ++i) {
		std::cout << arr[i] << std::endl;;
	}

	return 0;
}
