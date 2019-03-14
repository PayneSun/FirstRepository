// ch09_sequential_containers
// ch09_example.cpp
// 2017.04.18

/*
#include <iostream>
#include <string>
#include <array>
#include <list>
#include <vector>
#include <forward_list>


int main() {
	std::list<std::string> authors = {
		"Milton", "Shakespeare", "Austen"};
	auto it1 = authors.begin();
	auto it2 = authors.rbegin();
	auto it3 = authors.cbegin();
	auto it4 = authors.crbegin();

	std::array<int, 10> arr = {0};

	std::list<char *> list_pchar = {"How", "are", "you"};
	std::vector<std::string> vec_str;
	vec_str.assign(list_pchar.cbegin(), list_pchar.cend());
	for (auto it = vec_str.begin(); it != vec_str.end(); ++it) {
		std::cout << *it << std::endl;
	}

	std::vector<std::string> svec;
	std::list<std::string> slist;
	svec.insert(svec.end(), 10, "Anna");

	std::string word;
	std::list<std::string> lst;
	auto iter = lst.begin();
	while (std::cin >> word) {
		iter = lst.insert(iter, word);
	}

	std::list<int> ilst = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	auto it = ilst.begin();
	while (it != ilst.end()) {
		if (*it % 2)
			it = ilst.erase(it);
		else
			it++;
	}
	ilst.clear();
	ilst.erase(ilst.begin(), ilst.end());

	std::forward_list<int> flst = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	auto prev = flst.before_begin();
	auto curr = flst.begin();
	while (curr != flst.end()) {
		if (*curr % 2)
			curr = flst.erase_after(prev);
		else {
			prev = curr;
			curr++;
		}
	}

	return 0;
}
*/
