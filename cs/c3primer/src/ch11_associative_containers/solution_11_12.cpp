// ch11_associative_containers
// solution_11_12.cpp
// 2019.05.02


#include <iostream>
#include <string>
#include <vector>
#include <utility>


int main()
{
	std::vector<std::pair<std::string, int>> sipvec;

	std::string str;
	int val;
	while (std::cin >> str >> val) {
		sipvec.push_back(std::pair<std::string, int>{str, val});
//		sipvec.push_back(std::make_pair(str, val));
//		sipvec.push_back({str, val});
	}

	for (const auto ele : sipvec) {
		std::cout << ele.first << "\t" << ele.second << std::endl;
	}

	return 0;
}
