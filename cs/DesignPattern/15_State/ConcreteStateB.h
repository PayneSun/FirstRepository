// Design Pattern
// ConcreteStateB.h
// 2019.08.30

#ifndef CONCRETESTATEB_H
#define CONCRETESTATEB_H

#include "State.h"
#include "Context.h"


class ConcreteStateB: public State
{
public:
	static State* Instance();
	void handle(Context *pc);

private:
	ConcreteStateB();
	static State *ps;
};

#endif //CONCRETESTATEB_H
