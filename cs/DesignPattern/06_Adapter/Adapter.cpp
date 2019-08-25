// Design Pattern
// Adapter.cpp
// 2019.08.25

#include <iostream>


class Adaptee
{
public:
	void specificRequest() {
		std::cout << "Adaptee::specificRequest()" << std::endl;
	}
};


class Target
{
public:
	virtual void request() {}
};


class Adapter: public Target
{
public:
	Adapter(Adaptee *adaptee) {
		this->adaptee = adaptee;
	}
	void request() {
		adaptee->specificRequest();
	}

private:
	Adaptee *adaptee;
};


int main()
{
	Adaptee *adaptee = new Adaptee();
	Target *target = new Adapter(adaptee);
	target->request();

	return 0;
}
