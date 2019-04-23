// ch09_sequential_containers
// solution_09_28.cpp
// 2019.04.23

#include <iostream>
#include <string>
#include <forward_list>

void func(std::forward_list<std::string> &flstr, const std::string &str1,
		const std::string &str2) {
	auto prev = flstr.before_begin();
	auto curr = flstr.begin();

	while (curr != flstr.end()) {
		if (*curr == str1) {
			flstr.insert_after(curr, str2);
			break;
		} else {
			prev = curr;
			++curr;
		}
	}

	if (curr == flstr.end()) {
		flstr.insert_after(prev, str2);
	}
}

int main() {
	std::forward_list<std::string> flstr = { "welcome", "to", "china" };

	std::string str1 = "ho";
	std::string str2 = "XX";

	func(flstr, str1, str2);

	for (const auto ci : flstr) {
		std::cout << ci << std::endl;
	}

	return 0;
}
