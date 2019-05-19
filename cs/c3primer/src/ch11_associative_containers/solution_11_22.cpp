// ch11_associative_containers
// solution_11_22.cpp
// 2019.05.03


#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <utility>


int main()
{
	std::map<std::string, std::vector<int>> svmap;
	std::pair<std::map<std::string, std::vector<int>>::iterator, bool> ret
//		= svmap.insert({"sun", std::vector<int>{1, 2, 3}});
		= svmap.insert(std::make_pair("sun", std::vector<int>{1, 2, 3}));

	std::cout << "size of svmap: " << svmap.size() << std::endl;

	return 0;
}
