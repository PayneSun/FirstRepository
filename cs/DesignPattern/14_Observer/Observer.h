// Design Pattern
// Mediator/Observer.h
// 2019.08.28

#ifndef OBSERVER_H
#define OBSERVER_H

#include "Observer.h"

#include <iostream>
#include <string>
#include <vector>


class Subject;


class Observer
{
public:
	virtual void update(Subject *ps) {}
};


class ConcreteObserver: public Observer
{
public:
	ConcreteObserver(const std::string &str): obName(str) {}
	void update(Subject *ps) {
		observerState = ps->getState();
		std::cout << "Update observer [" << obName << "] state: " << observerState << std::endl;
	}
private:
	int observerState;
	std::string obName;
};

#endif
