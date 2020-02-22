// Design Pattern
// ConcreteStateB.cpp
// 2019.08.30

#include "State.h"
#include "Context.h"
#include "ConcreteStateB.h"

#include <iostream>


State *ConcreteStateB::ps = NULL;


State* ConcreteStateB::Instance() {
	if (ps == NULL) {
		ps = new ConcreteStateA();
	}
	return ps;
}


void ConcreteStateB::handle(Context *pc) {
	std::cout << "ConcreteStateB::handle()" << std::endl;
	pc->changeState(ConcreteStateA::Instance());
}


ConcreteStateB::ConcreteStateB() {
	//
}
