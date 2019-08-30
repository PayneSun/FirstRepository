// Design Pattern
// Context.cpp
// 2019.08.30

#ifndef CONTEXT_H
#define CONTEXT_H

#include "State.h"
#include "ConcreteState.h"
#include <iostream>

class State;

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


#endif //CONTEXT_H
