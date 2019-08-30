// Design Pattern
// ConcreteState.h
// 2019.08.30

#ifndef CONCRETE_STATE_H
#define CONCRETE_STATE_H

#include "State.h"
#include "Context.h"

class State;

class ConcreteStateA: public State
{
public:
	static State* Instance();
	void handle(Context *pc);

private:
	ConcreteStateA();
	static State *ps;
};


class ConcreteStateB: public State
{
public:
	static State* Instance();
	void handle(Context *pc);

private:
	ConcreteStateB();
	static State *ps;
};

#endif //CONCRETE_STATE_H
