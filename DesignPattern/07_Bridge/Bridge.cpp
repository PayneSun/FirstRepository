// Design Pattern
// Adapter.cpp
// 2019.08.25

#include <iostream>


class Implementor
{
public:
	virtual void operationImp() {}
};


class ConcreteImplementorA: public Implementor
{
public:
	void operationImp() {
		std::cout << "ConcreteImplementorA::operationImp()" << std::endl;
	}
};


class ConcreteImplementorB: public Implementor
{
public:
	void operationImp() {
		std::cout << "ConcreteImplementorB::operationImp()" << std::endl;
	}
};


class Abstraction
{
public:
	Abstraction(Implementor *pImp) {
		this->pImp = pImp;
	}
	virtual void operation() {
		pImp->operationImp();
	}
private:
	Implementor *pImp;
};


class RefinedAbstraction: public Abstraction
{
public:
	RefinedAbstraction(Implementor *pImp): Abstraction(pImp) {
	}
	virtual void operation() {
		Abstraction::operation();
	}
};


int main()
{
	Implementor *pi = new ConcreteImplementorA();
	Abstraction *pa = new RefinedAbstraction(pi);
	pa->operation();

	Abstraction *pb = new RefinedAbstraction(new ConcreteImplementorB());
	pb->operation();

	delete pa;
	delete pb;

	return 0;
}
