// ch17_specialized_library_facilities
// real_random_engine.cpp
// 2019/6/19


#include <iostream>
#include <cmath>
#include <iomanip>


int main()
{
	std::cout << "default bool values: " << true << " " << false
			  << "\nalpha bool values: " << std::boolalpha
			  << true << " " << false << std::noboolalpha
			  << "\n" << false << " " << true << std::endl;

	std::cout << "-----------------------------------" << std::endl;
	std::cout << "default: " << 20 << " " << 1024 << std::endl;
	std::cout << "octal:" << std::oct << 20 << " " << 1024 << std::endl;
	std::cout << "hex:" << std::hex << 20 << " " << 1024 << std::endl;
	std::cout << "decimal:" << std::dec << 20 << " " << 1024 << std::endl;

	std::cout << "-----------------------------------" << std::endl;
	std::cout << "Precision: " << std::cout.precision() << ", Value: " << sqrt(2.0) << std::endl;
	std::cout.precision(12);
	std::cout << "Precision: " << std::cout.precision() << ", Value: " << sqrt(2.0) << std::endl;

	std::cout << "-----------------------------------" << std::endl;
	std::cout.precision(6);
	std::cout << "default format: " << 100 * sqrt(2.0) << "\n"
			  << "scientific: " << std::scientific << 100 * sqrt(2.0) << "\n"
			  << "fixed decimal: " << std::fixed << 100 * sqrt(2.0) << "\n"
			  << "hexadecimal: " << std::hexfloat << 100 * sqrt(2.0) << "\n"
			  << "use defaults: " << std::defaultfloat << 100 * sqrt(2.0) << std::endl;

	std::cout << "-----------------------------------" << std::endl;
	int i = -16;
	double d = 3.14159;
	std::cout << "i: " << std::setw(12) << i << "next col" << '\n'
			  << "d: " << std::setw(12) << d << "next col" << '\n';
	std::cout << std::left
			  << "i: " << std::setw(12) << i << "next col" << '\n'
			  << "d: " << std::setw(12) << d << "next col" << '\n';
	std::cout << std::right
			  << "i: " << std::setw(12) << i << "next col" << '\n'
			  << "d: " << std::setw(12) << d << "next col" << '\n';
	std::cout << std::internal
			  << "i: " << std::setw(12) << i << "next col" << '\n'
			  << "d: " << std::setw(12) << d << "next col" << '\n';
	std::cout << std::setfill('#')
			  << "i: " << std::setw(12) << i << "next col" << '\n'
			  << "d: " << std::setw(12) << d << "next col" << '\n'
			  << std::setfill(' ');

	return 0;
}
