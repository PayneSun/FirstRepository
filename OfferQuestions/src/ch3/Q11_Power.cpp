// Q11_Power.cpp
//
// 2019.10.08

#include <iostream>


double power(double base, int exp);
bool equal(double num1, double num2);
double powerWithUnsignedExp(double base, unsigned int exp);


bool equal(double num1, double num2) {
	if (num1 - num2 > -0.00000001 && num1 - num2 < 0.00000001) {
		return true;
	} else {
		return false;
	}
}


double powerWithUnsignedExp(double base, unsigned int exp) {
	if (exp == 0) {
		return 1;
	}
	if (exp == 1) {
		return base;
	}

	double result = powerWithUnsignedExp(base, exp >> 1);
	result *= result;
	if (exp & 0x01 == 1) {
		result *= base;
	}

	return result;
}


double power(double base, int exp) {
	if(equal(base, 0.0) && exp < 0) {
		return 0.0;
	}

	unsigned int absExp = (unsigned int)(exp);
	if (exp < 0) {
		absExp = (unsigned int)(-exp);
	}
	double result = powerWithUnsignedExp(base, absExp);
	if (exp < 0) {
		result = 1.0 / result;
	}

	return result;
}


int main()
{
	std::cout << power(5, 3) << std::endl;
	std::cout << power(5, -3) << std::endl;
	std::cout << power(-1.5, 3) << std::endl;
	std::cout << power(-1.5, -3) << std::endl;
	std::cout << power(0, 0) << std::endl;
	std::cout << power(0, 3) << std::endl;
	std::cout << power(0, -3) << std::endl;

	return 0;
}
