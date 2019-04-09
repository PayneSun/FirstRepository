// ch05_statement
// solution_05_18.cpp
// 2019/4/4


#include <iostream>

int main()
{
	do {
		int v1, v2;
		std::cout << "Please enter two numbers to sum:";

		if (std::cin >> v1 >> v2)
			std::cout << "Sum is: " << v1 + v2 << std::endl;
	} while (std::cin);

	return 0;
}

