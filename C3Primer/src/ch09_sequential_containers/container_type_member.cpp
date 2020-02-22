// ch09_sequential_containers
// container_type_member.cpp
// 2019.04.18

#include <iostream>
#include <string>
#include <vector>


int main()
{
	std::vector<std::string> authors = {
		"Milton", "Shakespeare", "Austen"};

	std::vector<std::string>::iterator iter;
	std::vector<std::string>::value_type ele;
	std::vector<std::string>::difference_type cnt;

	iter = authors.begin();
	ele = *iter;
	cnt = authors.end() - authors.begin();

	std::cout << ele << std::endl;
	std::cout << cnt << std::endl;

	return 0;
}
