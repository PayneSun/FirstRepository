// shell_sort.cpp
//
// 2019/07/14

#include <iostream>
#include <vector>
#include <algorithm>


template<typename T>
void shellSort(T array[], int n)
{
	int gap = 0;
	while (gap <= n) {
		gap = gap * 3 + 1;
	}

	while (gap > 0) {
		for (int i = gap; i < n; ++i) {
			int j = i - gap,
				temp = array[i];
			while (j >= 0 && array[j] > temp) {
				array[j+gap] = array[j];
				j = j - gap;
			}
			array[j+gap] = temp;
		}
		gap = (gap - 1) / 3;
	}
}


int main()
{
	int array[] = {5, 4, 3, 7, 8, 9, 0, 2, 1, 6};

	shellSort(array, 10);

	for (int i = 0; i < 10; ++i) {
		std::cout << array[i] << " ";
	}

	return 0;
}
