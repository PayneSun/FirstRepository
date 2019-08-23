// Design Pattern
// FactoryMethod.cpp
// 2019.08.23

#include <iostream>
#include <string>


class Product
{
public:
	virtual std::string use() = 0;
};


class ConcreteProduct: public Product
{
public:
	std::string use() {
		return productName;
	}
private:
	std::string productName{"ConcreteProduct"};
};


class Factory
{
public:
	virtual Product* factoryMethod() = 0;
};


class ConcreteFactory: public Factory
{
public:
	Product* factoryMethod() {
		return new ConcreteProduct();
	}
};


int main()
{
	Factory *fc = new ConcreteFactory();
	Product *pd = fc->factoryMethod();

	std::cout << pd->use() << std::endl;

	delete fc;
	delete pd;

	return 0;
}
