// ch05_statement
// solution_05_10.cpp
// 2019/4/3


#include <iostream>


int main()
{
	unsigned arr[5] = {0, 0, 0, 0, 0};
	char chr[] = {'a', 'e', 'i', 'o', 'u'};

	char ch;
	while (std::cin >> ch) {
		switch (tolower(ch)) {
			case 'a':
				++arr[0]; break;
			case 'e':
				++arr[1]; break;
			case 'i':
				++arr[2]; break;
			case 'o':
				++arr[3]; break;
			case 'u':
				++arr[4]; break;
		}
	}

	for (std::size_t i = 0; i < 5; ++i) {
		std::cout << "Number of " << chr[i] << ": " << arr[i] << std::endl;
	}

	return 0;
}
