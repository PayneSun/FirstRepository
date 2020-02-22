// Design Pattern
// State.h
// 2019.08.30

#ifndef STATE_H
#define STATE_H

#include "Context.h"
#include <iostream>


class State
{
public:
	State();
	virtual ~State();
	virtual void handle(Context *);
};


State::State() {
	//
}


State::~State() {
	//
}


void State::handle(Context *) {
	//
}

#endif //STATE_H
