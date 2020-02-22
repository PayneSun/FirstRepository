// Design Pattern
// AbstractFactory.cpp
// 2019.08.23

#include <iostream>
#include <string>


class AbstractProductA
{
public:
	virtual void use() = 0;
};


class ConcreteProductA1: public AbstractProductA
{
public:
	void use() {
		std::cout << "ConcreteProductA1" << std::endl;
	}
};


class ConcreteProductA2: public AbstractProductA
{
public:
	void use() {
		std::cout << "ConcreteProductA2" << std::endl;
	}
};


class AbstractProductB
{
public:
	virtual void eat() = 0;
};


class ConcreteProductB1: public AbstractProductB
{
public:
	virtual void eat() {
		std::cout << "ConcreteProductB1" << std::endl;
	}
};


class ConcreteProductB2: public AbstractProductB
{
public:
	virtual void eat() {
		std::cout << "ConcreteProductB2" << std::endl;
	}
};


class AbstractFactory
{
public:
	virtual AbstractProductA* concreteProductA() = 0;
	virtual AbstractProductB* concreteProductB() = 0;
};


class ConcreteFactory1: public AbstractFactory
{
public:
	virtual AbstractProductA* concreteProductA() {
		return new ConcreteProductA1();
	}
	virtual AbstractProductB* concreteProductB() {
		return new ConcreteProductB1();
	}
};


class ConcreteFactory2: public AbstractFactory
{
public:
	virtual AbstractProductA* concreteProductA() {
		return new ConcreteProductA2();
	}

	virtual AbstractProductB* concreteProductB() {
		return new ConcreteProductB2();
	}
};


int main()
{
	AbstractFactory *af1 = new ConcreteFactory1();
	AbstractProductA *apa1 = af1->concreteProductA();
	AbstractProductB *apb1 = af1->concreteProductB();
	apa1->use();
	apb1->eat();

	AbstractFactory *af2 = new ConcreteFactory2();
	AbstractProductA *apa2 = af2->concreteProductA();
	AbstractProductB *apb2 = af2->concreteProductB();
	apa2->use();
	apb2->eat();

	delete af1;
	delete apa1;
	delete apb1;

	delete af2;
	delete apa2;
	delete apb2;

	return 0;
}
