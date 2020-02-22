//
//
//

#include <iostream>

// µÝ¹é
long long fib1(int n)
{
	return (n < 2) ? n : (fib1(n-1) + fib1(n-2));
}


// ¶¯Ì¬¹æ»®
long long fib2(int n)
{
	long long f = 0, g = 1;
	while (n > 1) {
		g = g + f;
		f = g - f;
		n--;
		std::cout << "g=" << g << ", f=" << f << std::endl;
	}

	return g;
}


int main()
{

	std::cout << fib2(8) << std::endl;

	return 0;
}
