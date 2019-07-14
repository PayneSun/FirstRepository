// binary_insert_sort.cpp
//
// 2019/07/14

#include <iostream>
#include <algorithm>


template<typename T>
void binaryInsertSort(T array[], int n)
{
	for (int i = 1; i < n; ++i) {
		int middle, left = 0, right = i - 1, temp = array[i];
		while (left <= right) {
			middle = (left + right) / 2;
			if (array[middle] < temp) {
				left = middle + 1;
			} else {
				right = middle - 1;
			}
		}
		for (int j = i; j > left; --j) {
			array[j] = array[j-1];
		}
		array[left] = temp;
	}
}


int main()
{
	int array[] = {9, 48, 7, 3, 22, 1, 0, 16, 15, 14};
	binaryInsertSort(array, 10);

	for (int i = 0; i < 10; ++i) {
		std::cout << array[i] << " ";
	}

	return 0;
}
