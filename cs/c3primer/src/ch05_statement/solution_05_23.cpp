// ch05_statement
// solution_05_23.cpp
// 2019/4/5


#include <iostream>
#include <stdexcept>


int main()
{
	try {
		int val1, val2;
		std::cin >> val1 >> val2;
		if(val2 == 0) {
			throw std::runtime_error("invalid input");
		}
		std::cout << "result = " << 1.0 * val1 / val2 << std::endl;
	} catch (const std::exception &ex) {
		std::cout << ex.what() << std::endl;
	}

	return 0;
}

