/**
 * ch_02_algorithm_analysis/example.cpp
 *
 * 2020.03.30
 */

#include "define.h"

//
template<typename T>
int binarySearch(const T A[], T X, int N) {
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

//
unsigned int gcd(unsigned int M, unsigned int N) {
	unsigned int Rem;
	while (N > 0) {
		Rem = M % N;
		M = N;
		N = Rem;
	}

	return M;
}

//
long int pow(long int X, unsigned int N) {
	if (N == 0) {
		return 1;
	}

	if (N % 2) {
		return pow(X * X, N / 2) * X;
	} else {
		return pow(X * X, N / 2);
	}
}
