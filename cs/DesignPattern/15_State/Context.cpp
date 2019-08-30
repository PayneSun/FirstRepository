// Design Pattern
// Context.cpp
// 2019.08.30

#include "State.h"
#include "ConcreteState.h"


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
