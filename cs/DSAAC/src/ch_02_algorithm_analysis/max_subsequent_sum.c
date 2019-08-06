/******************************************
 * ch_02_algorithm_analysis/max_subsequent_sum.c
 *
 * 2017.09.26
 *****************************************/


/*
 *
 */
int MaxSubsequentSum1(const int A[], int N) {
	int ThisSum, MaxSum, i, j, k;

	MaxSum = 0;
	for (i = 0; i < N; i++) {
		for (j = i; j < N; j++) {
			ThisSum = 0;
			for (k = i; k <= j; k++) {
				ThisSum += A[k];
			}

			if (ThisSum > MaxSum) {
				MaxSum = ThisSum;
			}
		}
	}

	return MaxSum;
}


/*
 *
 */
int MaxSubsequentSum2(const int A[], int N) {
	int ThisSum, MaxSum, i, j;

	MaxSum = 0;
	for (i = 0; i < N; i++) {
		ThisSum = 0;
		for (j = i; j < N; j++) {
			ThisSum += A[j];

			if (ThisSum > MaxSum) {
				MaxSum = ThisSum;
			}
		}
	}

	return MaxSum;
}


/*
 *
 */
static int MaxSubsequentSum3(const int A[], int Left, int Right) {
	int MaxLeftSum, MaxRightSum;
	int MaxLeftBorderSum, MaxRightBorderSum;
	int LeftBorderSum, RightBorderSum;
	int Center, i;

	if (Left == Right) {
		if (A[Left] > 0) {
			return A[Left];
		} else {
			return 0;
		}
	}

	Center = (Left + Right) / 2;
	MaxLeftSum = MaxSubSum(A, Left, Center);
	MaxRightSum = MaxSubSum(A, Center, Right);

	LeftBorderSum = 0;
	MaxLeftBorderSum = 0;
	for (i = Center; i >= Left; i--) {
		LeftBorderSum += A[i];
		if (LeftBorderSum > MaxLeftBorderSum) {
			MaxLeftBorderSum = LeftBorderSum;
		}
	}

	RightBorderSum = 0;
	MaxRightBorderSum = 0;
	for (i = Center + 1; i <= Left; i++) {
		RightBorderSum += A[i];
		if (RightBorderSum > MaxRightBorderSum) {
			MaxRightBorderSum = RightBorderSum;
		}
	}

	return Max3(MaxLeftSum, MaxRightSum, MaxLeftBorderSum + MaxRightBorderSum);
}


/*
 *
 */
int MaxSubsequentSum4(const int A[], int N) {
	int ThisSum, MaxSum, j;

	ThisSum = MaxSum = 0;
	for (j = 0; j < N; j++) {
		ThisSum += A[j];

		if (ThisSum > MaxSum) {
			MaxSum = ThisSum;
		} else if (ThisSum < 0) {
			ThisSum = 0;
		}
	}

	return MaxSum;
}
