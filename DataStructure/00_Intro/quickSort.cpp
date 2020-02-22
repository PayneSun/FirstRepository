// Algorithm/DivideConquer
// quickSort.cpp
// 2019/09/11

#include <iostream>
#include <algorithm>


template<typename T>
int partition(T a[], int left, int right)
{
	int i = left, j = right;
	T x = a[left];
	while (true) {
		while (i < right && a[i] <= x) { ++i; }
		while (j > left && a[j] >= x) { --j; }
		if (i >= j) {
			break;
		}
		std::swap(a[i], a[j]);
	}

	a[left] = a[j];
	a[j] = x;
	return j;
}


template<typename T>
void quickSort(T a[], int left, int right) {
	if (left < right) {
		int q = partition(a, left, right);
		quickSort(a, left, q-1);
		quickSort(a, q+1, right);
	}
}


int main()
{
	int a[] = {1,4,2,3,5};

	quickSort(a, 0, 4);
	for (int i = 0; i < 5; ++i) {
		std::cout << a[i] << std::endl;
	}

	return 0;
}
