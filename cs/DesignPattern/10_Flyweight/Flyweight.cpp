// Design Pattern
// Flyweight.cpp
// 2019.08.26

#include <iostream>
#include <string>
#include <map>


class Flyweight
{
public:
	virtual void operation() {}
};


class ConcreteFlyweight: public Flyweight
{
public:
	ConcreteFlyweight(const std::string &str): intrinsicState(str) {}
	void operation() {
		std::cout << "ConcreteFlyweight: " << intrinsicState << std::endl;
	}
private:
	std::string intrinsicState;
};


class FlyweightFactory
{
public:
	Flyweight* getFlyweight(const std::string &key) {
		auto it = mapFlyweight.find(key);
		if (it != mapFlyweight.end()) {
			std::cout << "Already in the pool, use the exist one:" << std::endl;
		    return it->second;
		} else {
			Flyweight *pf = new ConcreteFlyweight(key);
		    mapFlyweight.insert(std::make_pair(key, pf));
		    return pf;
		}
	}
private:
	std::map<std::string, Flyweight*> mapFlyweight;
};


int main()
{
	FlyweightFactory factory;
	Flyweight *fw1 = factory.getFlyweight("one");
	fw1->operation();

	Flyweight *fw2 = factory.getFlyweight("two");
	fw2->operation();

	//already exist in pool
	Flyweight *fw3 = factory.getFlyweight("one");
	fw3->operation();

	return 0;
}
