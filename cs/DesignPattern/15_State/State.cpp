// Design Pattern
// State.cpp
// 2019.08.30

#include <iostream>
#include <string>
#include <map>


class Context
{
public:
	Context() {
		ps = new ConcreteStateA::Instance();
	}
	void changeState(State *ps) {
		this->ps = ps;
	}
	void request() {
		ps->handle(this);
	}
private:
	State *ps;
};


class ConcreteStateA: public State
{
public:
	static State* Instance() {
		if (ps == NULL) {
			ps = new ConcreteStateA();
		}
		return ps;
	}
	virtual void handle(Context *pc) {
		std::cout << "ConcreteStateA::handle()" << std::endl;
		pc->changeState(ConcreteStateB::Instance());
	}

private:
	ConcreteStateA() {}
	static State *ps;
};


class ConcreteStateB: public State
{
public:
	static State* Instance() {
		if (ps == NULL) {
			ps = new ConcreteStateA();
		}
		return ps;
	}
	virtual void handle(Context *pc) {
		std::cout << "ConcreteStateB::handle()" << std::endl;
		pc->changeState(ConcreteStateA::Instance());
	}

private:
	ConcreteStateB() {}
	static State *ps;
};


int main()
{
	Context *pc = new Context();
	pc->request();
	pc->request();
	pc->request();

	delete pc;

	return 0;
}
