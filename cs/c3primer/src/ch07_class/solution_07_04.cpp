


#include <string>


class Person {
	std::string name;
	std::string addr;

	Person(const std::string &name, const std::string &addr) :
		name(name), addr(addr) {}

	std::string getName() const {
		return this->name;
	}

	std::string getAdds() const {
		return this->addr;
	}
};


std::istream &read(std::istream &is, Person &per) {
    is >> per.name >> per.addr;

    return is;
}


std::ostream &print(std::ostream &os, const Person &per) {
    os << per.getName() << " " << per.getAdds();

    return os;
}
