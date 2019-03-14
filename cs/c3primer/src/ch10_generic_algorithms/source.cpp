// ch10_generic_algorithms
// ch10_example.cpp
// 2017.04.21

/*
#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <iterator>
#include <string>
#include <istream>
#include <ostream>


int main() {

	//int ia[] = { 27, 210, 12, 47, 109, 83 };
	//int val = 83;
	//int* result = std::find(std::begin(ia), std::end(ia), val);
	//std::cout << (result - ia) << std::endl;

	//std::vector<int> vint;
	//for (int i = 1; i <= 10; ++i) {
	//	vint.push_back(i);
	//}
	//auto result = std::accumulate(vint.cbegin(), vint.cend(), 0);
	//std::cout << vint.capacity() << std::endl;

	//std::vector<int> vec;
	//std::fill_n(back_inserter(vec), 10, 3);
	//auto result = std::accumulate(vec.cbegin(), vec.cend(), 0);
	//std::cout << result << std::endl;

	//int ia = 3, ib = 4;
	//auto cc = [ia, ib] () { return ia + ib; };
	//std::cout << cc() << std::endl;

	//auto wc = find_if(words.begin(), words.end(),
	//	[=](const std::string &s) { return s.size() >= sz; });

	//std::vector<int> vec;
	//std::istream_iterator<int> in_iter(std::cin);
	//std::istream_iterator<int> eof;
	//while (in_iter != eof) {
	//	vec.push_back(*in_iter++);
	//}

	return 0;
}
*/

/*
void biggies(std::vector<std::string> &words, std::vector<std::string>::size_type sz) {
	elimDups(words);
	std::stable_sort(words.begin(), words.end(),
		[](const std::string &a, const std::string &b){ return a.size() < b.size(); });

	auto wc = std::find_if(words.begin(), words.end(),
		[sz](const std::string &a){return a.size() >= sz; });

	auto count = words.end() - wc;
	std::cout << count << " " << make_plural(count, "words", "s")
		<< " of length " << sz << " or longer" << std::endl;

	std::for_each(wc, words.end(), [](const std::string &s) {std::cout << s << " "; });
	std::cout << std::endl;
}
*/

