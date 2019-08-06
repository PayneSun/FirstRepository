// ch11_associative_containers
// unordered_container.cpp
// 2019.05.04

#include <iostream>
#include <sstream>
#include <string>
#include <unordered_set>

struct Person {
	Person(std::string name, std::size_t year) :
			name(name), year(year) {
	}
	std::string name;
	std::size_t year;
};

std::size_t hasher(const Person &per) {
	return std::hash<std::size_t>()(per.year);
}

bool eqOp(const Person &lhs, const Person &rhs) {
	return lhs.year == rhs.year;
}

typedef std::unordered_multiset<Person, decltype(hasher)*, decltype(eqOp)*> umset_t;
//using umset_t = std::unordered_multiset<Person, decltype(hasher)*, decltype(eqOp)*>;

int main() {
	umset_t var(10, hasher, eqOp);
	var.insert(Person("sun", 25));

	std::cout << var.size() << std::endl;

	return 0;
}
