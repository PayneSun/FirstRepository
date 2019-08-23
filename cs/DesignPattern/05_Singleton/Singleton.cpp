// Design Pattern
// Singleton.cpp
// 2019.08.23

#include <iostream>


class Singleton
{
public:
	static Singleton* getInstance();
	void singletonOperation();
	~Singleton();

private:
	Singleton();
	static Singleton *instance;
};


Singleton* Singleton::instance = NULL;


Singleton::Singleton() {
	//
}


Singleton* Singleton::getInstance() {
	if (instance == NULL) {
		instance = new Singleton();
	}
	return instance;
}


void Singleton::singletonOperation() {
	std::cout << "singletonOperation" << std::endl;
}


Singleton::~Singleton() {
	delete instance;
}


int main()
{
	Singleton *sg = Singleton::getInstance();
	sg->singletonOperation();

	return 0;
}
