// ch16_templates_and_generic_programming
// solution_16_07.cpp
// 2019/6/8


#include <iostream>
#include <algorithm>


template<typename T>
constexpr int array_length(const T& arr)
{
	return sizeof(arr) / sizeof(arr[0]);
}


int main()
{
	char arr1[] = "hello";
	std::cout << array_length(arr1) << std::endl;

	int arr2[] = {1, 2, 3};
	std::cout << array_length(arr2) << std::endl;

	double arr3[] = {};
	std::cout << array_length(arr3) << std::endl;

	return 0;
}
