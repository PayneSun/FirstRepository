/******************************************
 * ch_02_algorithm_analysis/pow.c
 *
 * 2017.09.26
 *****************************************/


/*
 *
 */
long int Pow(long int X, unsigned int N) {
	if (N == 0) {
		return 1;
	} else if (N == 1) {
		return X;
	}

	if (IsEven(N)) {
		return Pow(X * X, N / 2);
	} else {
		return Pow(X * X, N / 2) * X;
	}
}
