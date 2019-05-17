// prog_04_03.cpp
// 2019.05.01


int is_prime(int n) {
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			return 0;
		}
	}

	return 1;
}
