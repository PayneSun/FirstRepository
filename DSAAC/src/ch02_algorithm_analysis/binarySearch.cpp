/**
 * ch_02_algorithm_analysis/binarySearch.cpp
 *
 * 2020.03.30
 */

template<typename T>
int binarySearch(const T A[], T X, int N)
{
	int low = 0, high = N - 1, mid;
	while (low <= high) {
		mid = (low + high) / 2;
		if (X < A[mid]) {
			high = mid;
		} else if (X > A[mid]) {
			low = mid + 1;
		} else {
			return mid;
		}
	}

	return -1;
}
