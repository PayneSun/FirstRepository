// Design Pattern
// Strategy.h
// 2019.08.30

#ifndef STRATEGY_H
#define STRATEGY_H

#include "Context.h"
#include <iostream>


class Strategy {
public:
	virtual void algorithm() {}
};


class ConcreteStrategyA: public Strategy {
public:
	void algorithm() {
		std::cout << "ConcreteStrategyA::algorithm()" << std::endl;
	}
};


class ConcreteStrategyB: public Strategy {
public:
	void algorithm() {
		std::cout << "ConcreteStrategyB::algorithm()" << std::endl;
	}
};

#endif //STRATEGY_H
