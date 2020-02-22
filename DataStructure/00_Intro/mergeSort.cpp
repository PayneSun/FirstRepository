// Algorithm/DivideConquer
// mergeSort.cpp
// 2019/09/11

#include <iostream>


int b[5];


template<typename T>
void merge(T a[], T b[], int left, int mid, int right)
{
	int i = left, j = mid + 1, k = 0;
	while (i <= mid && j <= right) {
		if (a[i] <= a[j]) {
			b[k++] = a[i++];
		} else {
			b[k++] = a[j++];
		}
	}

	while (i <= mid) {
		b[k++] = a[i++];
	}
	while (j <= right) {
		b[k++] = a[j++];
	}
}


template<typename T>
void copy(T a[], T b[], int left, int right)
{
	for (int i = 0; i <= right - left; ++i) {
		a[left+i] = b[i];
	}
}


template<typename T>
void mergeSort(T a[], int left, int right) {
	if (left < right) {
		int middle = left + (right - left) / 2;
		mergeSort(a, left, middle);
		mergeSort(a, middle+1, right);
		merge(a, b, left, middle, right);
		copy(a, b, left, right);
	}
}


int main()
{
	int a[] = {5,4,3,2,1};

	mergeSort(a, 0, 4);
	for (int i = 0; i < 5; ++i) {
		std::cout << a[i] << std::endl;
	}

	return 0;
}
