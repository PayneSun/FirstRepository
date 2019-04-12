// ch07_class.cpp
// solution_07_04.h
// 2019/4/11


#include <string>


class Person {
friend std::istream &read(std::istream &is, Person &per);
std::ostream &print(std::ostream &os, const Person &per);

public:
	Person() = default;
	Person(const std::string &name, const std::string &addr) :
		name(name), addr(addr) {}

	std::string getName() const {
		return this->name;
	}

	std::string getAdds() const {
		return this->addr;
	}
private:
	std::string name;
	std::string addr;
};


std::istream &read(std::istream &is, Person &per) {
    is >> per.name >> per.addr;

    return is;
}


std::ostream &print(std::ostream &os, const Person &per) {
    os << per.getName() << " " << per.getAdds();

    return os;
}
