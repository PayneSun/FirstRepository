// Design Pattern
// Context.h
// 2019.08.30

#ifndef CONTEXT_H
#define CONTEXT_H

#include "Strategy.h"


class Strategy;


class Context {
public:
	Context();
	void algorithm();
	void setStrategy(Strategy *ps);

private:
	Strategy *ps;
};


Context::Context() {
	//
}


void Context::algorithm() {
	ps->algorithm();
}


void Context::setStrategy(Strategy *ps) {
	this->ps = ps;
}

#endif //CONTEXT_H
