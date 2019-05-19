// ch11_associative_containers
// use_associative_container.cpp
// 2019.04.29


#include <iostream>
#include <string>
#include <map>
#include <set>


int main()
{
	std::map<std::string, std::size_t> word_count;
	std::set<std::string> exclude = { "The", "But", "And", "Or", "An", "A",	"the", "but", "and", "or", "an", "a"};

	std::string word;
	while (std::cin >> word) {
		if (exclude.find(word) == exclude.end()) {
			++word_count[word];
		}
	}

	for (const auto &w : word_count) {
		std::cout << w.first << " occurs " << w.second
			<< ((w.second > 1) ? " times" : "time") << std::endl;
	}

	auto x = toupper('c');

	return 0;
}
