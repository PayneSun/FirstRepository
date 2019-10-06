// Q09_Fibonacci.cpp
//
// 2019.09.27

#include <iostream>


long long fibonacci(int n) {
	if (n < 2) {
		return n;
	}

	int f = 0, g = 1;
	for (int i = 2; i <= n; ++i) {
		g += f;
		f = g;
	}

	return f;
}


int main()
{
	std::cout << fibonacci(5) << std::endl;

	return 0;
}
