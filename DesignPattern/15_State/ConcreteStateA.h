// Design Pattern
// ConcreteStateA.h
// 2019.08.30

#ifndef CONCRETESTATEA_H
#define CONCRETESTATEA_H

#include "State.h"
#include "Context.h"


class ConcreteStateA: public State
{
public:
	static State* Instance();
	void handle(Context *pc);

private:
	ConcreteStateA();
	static State *ps;
};


#endif //CONCRETESTATEA_H
