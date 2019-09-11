// Algorithm/DivideConquer
// binarySearch.cpp
// 2019/09/11

#include <iostream>


template<typename T>
int binarySearch(T a[], int n, T x) {
	int left = 0, right = n - 1;
	while (left <= right) {
		int middle = left + (right - left) / 2;
		if (a[middle] < x) {
			left = middle + 1;
		} else if (a[middle] > x) {
			right = middle - 1;
		} else {
			return middle;
		}
	}

	return -1;
}


int main()
{
	int a[] = {1,2,3,4,5};

	std::cout << binarySearch(a,5,0) << std::endl;
	std::cout << binarySearch(a,5,1) << std::endl;
	std::cout << binarySearch(a,5,3) << std::endl;
	std::cout << binarySearch(a,5,5) << std::endl;
	std::cout << binarySearch(a,5,6) << std::endl;

	return 0;
}
