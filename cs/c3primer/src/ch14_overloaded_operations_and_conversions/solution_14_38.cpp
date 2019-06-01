// ch14_overloaded_operations_and_conversions
// solution_14_38.cpp
// 2019/6/1


#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <algorithm>


class CheckStrLen
{
public:
	CheckStrLen(std::size_t n): sz(n) {}
	bool operator()(const std::string &str) const {
		return str.size() == sz;
	}
private:
	std::size_t sz;
};


int main()
{
	std::ifstream ifs("city.txt");

	std::string line, word;
	std::vector<std::string> svec;
	while (getline(ifs, line)) {
		std::istringstream iss(line);
		while (iss >> word) {
			svec.push_back(word);
		}
	}

	std::vector<int> ivec(10,0);
	for (std::size_t i = 0; i < 10; ++i) {
		CheckStrLen csl(i+1);
		for (auto word : svec) {
			if (csl(word)) {
				ivec[i] += 1;
			}
		}
	}

	for (std::size_t i = 0; i < 10; i++) {
		std::cout << "Size " << i+1 << ": " << ivec[i] << std::endl;
	}

	return 0;
}
