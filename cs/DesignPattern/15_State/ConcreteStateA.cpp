// Design Pattern
// ConcreteStateA.cpp
// 2019.08.30

#include "State.h"
#include "Context.h"
#include "ConcreteStateA.h"

#include <iostream>


State* ConcreteStateA::ps = NULL;


State* ConcreteStateA::Instance() {
	if (ps == NULL) {
		ps = new ConcreteStateA();
	}
	return ps;
}


void ConcreteStateA::handle(Context *pc) {
	std::cout << "ConcreteStateA::handle()" << std::endl;
	pc->changeState(ConcreteStateB::Instance());
}


ConcreteStateA::ConcreteStateA() {
	//
}
