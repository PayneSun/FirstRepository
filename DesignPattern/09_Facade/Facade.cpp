// Design Pattern
// Facade.cpp
// 2019.08.26

#include <iostream>


class SystemA
{
public:
	void operationA() {
		std::cout << "SystemA::operationA()" << std::endl;
	}
};


class SystemB
{
public:
	void operationB() {
		std::cout << "SystemB::operationB()" << std::endl;
	}
};


class SystemC
{
public:
	void operationC() {
		std::cout << "SystemC::operationC()" << std::endl;
	}
};


class Facade
{
public:
	Facade() {
		psa = new SystemA();
		psb = new SystemB();
		psc = new SystemC();
	}
	void wrapOperation() {
		psa->operationA();
		psb->operationB();
		psc->operationC();
	}
	virtual ~Facade() {
		delete psa;
		delete psb;
		delete psc;
	}
private:
	SystemA *psa;
	SystemB *psb;
	SystemC *psc;
};


int main()
{
	Facade fa;
	fa.wrapOperation();

	return 0;
}
