// Design Pattern
// SimpleFactory.cpp
// 2019/8/10

#include <iostream>
#include <string>


class Product
{
public:
	virtual std::string getProductName() = 0;
};


class ConcreteProductA: public Product
{
public:
	std::string getProductName() {
		return productName;
	}
private:
	std::string productName{"ConcreteProductA"};
};


class ConcreteProductB: public Product
{
public:
	std::string getProductName() {
		return productName;
	}
private:
	std::string productName{"ConcreteProductB"};
};


class Factory
{
public:
	Product* createProduct(std::string productName) {
		if (productName == "ConcreteProductA") {
			return new ConcreteProductA();
		} else {
			return new ConcreteProductB();
		}
	}
};


int main()
{
	Factory fact;
	std::string productName("ConcreteProductX");

	auto pcp = fact.createProduct(productName);
	std::cout << pcp->getProductName() << std::endl;

	return 0;
}
