// Design Pattern
// State.h
// 2019.08.30

#ifndef STATE_H
#define STATE_H

#include "Context.h"


class State
{
public:
	State() {}
	virtual ~State() {}
	virtual void handle(Context *pc) {}
};


#endif //STATE_H
