// Design Pattern
// ConcreteState.cpp
// 2019.08.30

#include "State.h"
#include "Context.h"
#include <iostream>


State *ConcreteStateA::ps = NULL;


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

