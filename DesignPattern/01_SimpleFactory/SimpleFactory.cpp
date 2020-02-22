// Design Pattern
// SimpleFactory.cpp
// 2019.08.10

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
	static Product* createProduct(std::string productName) {
		if (productName == "ConcreteProductA") {
			return new ConcreteProductA();
		} else {
			return new ConcreteProductB();
		}
	}
};


int main()
{
	std::string productName("ConcreteProductX");
	auto pcp = Factory::createProduct(productName);

	std::cout << pcp->getProductName() << std::endl;

	return 0;
}
