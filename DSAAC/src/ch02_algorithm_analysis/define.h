/**
 * ch02_algorithm_analysis/define.h
 *
 * 2020.03.30
 */

#ifndef CH02_ALGORITHM_ANALYSIS_DEFINE_H_
#define CH02_ALGORITHM_ANALYSIS_DEFINE_H_

template<typename T>
int binarySearch(const T A[], T X, int N);
unsigned int gcd(unsigned int M, unsigned int N);
long int pow(long int X, unsigned int N);

int maxSubSum(const int A[], int left, int right);
int maxSubsequentSum1(const int A[], int N);
int maxSubsequentSum2(const int A[], int N);
int maxSubsequentSum3(const int A[], int N);
int maxSubsequentSum4(const int A[], int N);

#endif /* CH02_ALGORITHM_ANALYSIS_DEFINE_H_ */
