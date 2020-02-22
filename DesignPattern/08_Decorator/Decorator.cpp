// Design Pattern
// Decorator.cpp
// 2019.08.25

#include <iostream>


class Component
{
public:
	virtual void operation() {}
};


class ConcreteComponent: public Component
{
public:
	void operation() {
		std::cout << "ConcreteComponent::operation()" << std::endl;
	}
};


class Decorator: public Component
{
public:
	Decorator(Component *pc): pc(pc) {}
	virtual void operation() {
		pc->operation();
	}
private:
	Component *pc;
};


class ConcreteDecoratorA: public Decorator
{
public:
	ConcreteDecoratorA(Component *pc): Decorator(pc) {}
	void operation() {
		Decorator::operation();
		addBehavior();
	}
	void addBehavior() {
		std::cout << "ConcreteDecoratorA::addBehavior()" << std::endl;
	}
};


class ConcreteDecoratorB: public Decorator
{
public:
	ConcreteDecoratorB(Component *pc): Decorator(pc) {}
	void operation() {
		Decorator::operation();
		addBehavior();
	}
	void addBehavior() {
		std::cout << "ConcreteDecoratorB::addBehavior()" << std::endl;
	}
};


int main()
{
	Component *pc = new ConcreteComponent();
	Decorator *pda = new ConcreteDecoratorA(pc);
	Decorator *pdb = new ConcreteDecoratorB(pc);

	pda->operation();
	pdb->operation();

	delete pc;
	delete pda;
	delete pdb;

	return 0;
}
