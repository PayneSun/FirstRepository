


#include <string>


class Person {
	std::string name;
	std::string adds;

	std::string getName() const {
		return this->name;
	}

	std::string getAdds() const {
		return this->adds;
	}
};
