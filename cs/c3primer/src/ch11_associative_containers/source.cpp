// ch11_associative_containers
// source.cpp
// 2017/4/28

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <utility>

using namespace std;


int main() {
	string word;
	map<string, size_t> word_count;
	set<string> exclude = { "The", "But", "And", "Or", "An", "A",
							"the", "but", "and", "or", "an", "a"};
	while (cin >> word) {
		if (exclude.find(word) == exclude.end())
		++word_count[word];
	}
	for (const auto &w : word_count) {
		cout << w.first << " occurs " << w.second
			<< ((w.second > 1) ? " times" : "time") << endl;
	}

	vector<int> ivec;
	for (vector<int>::size_type i = 0; i != 10; ++i) {
		ivec.push_back(i);
		ivec.push_back(i);
	}
	set<int> iset(ivec.begin(), ivec.end());
	multiset<int> miset(ivec.cbegin(), ivec.cend());
	cout << iset.size() << endl;
	cout << miset.size() << endl;

	pair<string, vector<int>> line;
	pair<string, string> author{ "James", "Joyce" };

	set<string>::value_type v1;
	set<string>::key_type v2;
	map<string, int>::value_type v3;
	map<string, int>::key_type v4;
	map<string, int>::mapped_type v5;

	set<int> iset = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	set<int>::iterator set_it = iset.begin();
	while (set_it != iset.end()) {
		cout << *set_it++ << " ";
	}

	multimap<string, string> authors;
	authors.insert({ "Barth, John", "Sot-Weed Factor" });
	authors.insert({ "Barth, John", "Lost in the Funhouse" });
	auto cnt = authors.erase("Barth, John");

	map<string, size_t> word_count;
	word_count["Anna"] = 1;

	string search_item("Alain de Botton");
	auto entries = authors.count(search_item);
	auto iter = authors.find(search_item);
	while (entries) {
		cout << iter->second << endl;
		++iter;
		--entries;
	}
	for (auto beg = authors.lower_bound(search_item),
		end = authors.upper_bound(search_item);
		beg != end; ++beg) {
		cout << beg->second << endl;
	}
	for (auto pos = authors.equal_range(search_item);
		pos.first != pos.second; ++pos.first) {
		cout << pos.first->second;
	}

	std::unordered_map<string, size_t> word_count;
	string word;
	while (cin >> word) {
		++word_count[word];
	}
	for (const auto &w : word_count) {
		cout << w.first << " occurs " << w.second
			<< ((w.second > 1) ? " times." : " time") << endl;
	}

	return 0;
}
