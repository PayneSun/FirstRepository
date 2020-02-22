// Design Pattern
// Context.cpp
// 2019.08.30

#ifndef CONTEXT_H
#define CONTEXT_H

#include "State.h"


class State;
class ConcreteStateA;


class Context
{
public:
	Context();
	void changeState(State *ps);
	void request();
	virtual ~Context();

private:
	State *ps;
};


Context::Context() {
	ps = new ConcreteStateA::Instance();
}


void Context::changeState(State *ps) {
	this->ps = ps;
}


void Context::request() {
	ps->handle(this);
}


Context::~Context() {
	//
}

#endif //CONTEXT_H
