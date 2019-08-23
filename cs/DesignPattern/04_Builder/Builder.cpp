// Design Pattern
// Builder.cpp
// 2019.08.23

#include <iostream>
#include <string>


struct Product
{
	void show() {
		std::cout << "Product: " << "a=" << a << ", b=" << b << ", c=" << c << std::endl;
	}
	int a;
	int b;
	int c;
};


class Builder
{
public:
	virtual void buildPartA() = 0;
	virtual void buildPartB() = 0;
	virtual void buildPartC() = 0;
	virtual Product* getResult() = 0;
};


class ConcreteBuilder: public Builder
{
public:
	ConcreteBuilder() { p = new Product(); }
	void buildPartA() {	p->a = 10; }
	void buildPartB() { p->b = 20; }
	void buildPartC() { p->c = 30; }
	Product* getResult() { return p; }
private:
	Product *p;
};


class Director
{
public:
	void setBuilder(Builder *builder) {
		pBuilder = builder;
	}

	Product* construct() {
		pBuilder->buildPartA();
		pBuilder->buildPartB();
		pBuilder->buildPartC();

		return pBuilder->getResult();
	}

private:
	Builder *pBuilder;
};


int main()
{
	ConcreteBuilder *builder = new ConcreteBuilder();
	Director director;
	director.setBuilder(builder);
	Product *pd = director.construct();
	pd->show();

	delete builder;
	delete pd;

	return 0;
}
