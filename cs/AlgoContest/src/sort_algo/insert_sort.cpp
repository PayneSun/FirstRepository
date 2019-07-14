// insert_sort.cpp
//
// 2019/07/14

#include <iostream>
#include <algorithm>


template<typename T>
void insertSort(T array[], int len)
{
	for (int i = 1; i < len; ++i) {
		int j = i, tmp = array[i];
		while (j > 0 && array[j-1] > tmp) {
			array[j] = array[j-1];
			j--;
		}
		array[j] = tmp;
	}
}


int main()
{
	int array[] = {9, 48, 7, 3, 22, 1, 0, 16, 15, 14};
	insertSort(array, 10);

	for (int i = 0; i < 10; ++i) {
		std::cout << array[i] << " ";
	}

	return 0;
}
