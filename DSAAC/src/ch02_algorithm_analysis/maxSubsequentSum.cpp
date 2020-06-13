/**
 * ch02_algorithm_analysis/max_subsequent_sum.cpp
 *
 * 2020.03.30
 */

#include "define.h"
#include <algorithm>

// O(n^3)解法
int maxSubsequentSum1(const int A[], int N) {
	int thisSum = 0, maxSum = 0;

	for (int i = 0; i < N; i++) {
		for (int j = i; j < N; j++) {
			thisSum = 0;
			for (int k = i; k <= j; k++) {
				thisSum += A[k];
			}

			if (thisSum > maxSum) {
				maxSum = thisSum;
			}
		}
	}

	return maxSum;
}

// O(n^2)解法
int maxSubsequentSum2(const int A[], int N) {
	int thisSum = 0, maxSum = 0;

	for (int i = 0; i < N; i++) {
		thisSum = 0;
		for (int j = i; j < N; j++) {
			thisSum += A[j];

			if (thisSum > maxSum) {
				maxSum = thisSum;
			}
		}
	}

	return maxSum;
}

// O(nlogn)解法
int maxSubSum(const int A[], int left, int right) {
	if (left == right) {
		return (A[left] > 0) ? A[left] : 0;
	}

	int maxLeftSum, maxRightSum, center = (left + right) / 2;
	maxLeftSum = maxSubSum(A, left, center);
	maxRightSum = maxSubSum(A, center + 1, right);

	int leftBorderSum = 0, maxLeftBorderSum = 0;
	for (int i = center; i >= left; i--) {
		leftBorderSum += A[i];
		if (leftBorderSum > maxLeftBorderSum) {
			maxLeftBorderSum = leftBorderSum;
		}
	}

	int rightBorderSum = 0, maxRightBorderSum = 0;
	for (int i = center + 1; i <= right; i++) {
		rightBorderSum += A[i];
		if (rightBorderSum > maxRightBorderSum) {
			maxRightBorderSum = rightBorderSum;
		}
	}

	return std::max(std::max(maxLeftSum, maxRightSum),
			maxLeftBorderSum + maxRightBorderSum);
}

int maxSubsequentSum3(const int A[], int N) {
	return maxSubSum(A, 0, N - 1);
}

// O(n)解法
int maxSubsequentSum4(const int A[], int N) {
	int thisSum = 0, maxSum = 0;
	for (int j = 0; j < N; j++) {
		thisSum += A[j];

		if (thisSum > maxSum) {
			maxSum = thisSum;
		} else if (thisSum < 0) {
			thisSum = 0;
		}
	}

	return maxSum;
}
