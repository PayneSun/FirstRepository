// bubble_sort.cpp
//
// 2019/07/14

#include <iostream>
#include <algorithm>


template<typename T>
void bubbleSort(T array[], int n)
{
	for (int i = 0; i < n; ++i) {
		for (int j = 1; j < n - i; ++j) {
			if (array[j-1] > array[j]) {
				std::swap(array[j-1], array[j]);
			}
		}
	}
}


int main()
{
	int array[] = {9, 8, 7, 3, 2, 1, 0, 6, 5, 4};

	bubbleSort(array, 10);

	for (int i = 0; i < 10; ++i) {
		std::cout << array[i] << " ";
	}

	return 0;
}
