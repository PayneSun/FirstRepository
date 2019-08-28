// Design Pattern
// Observer.cpp
// 2019.08.28

#include "Subject.h"
#include "Observer.h"

#include <iostream>
#include <string>
#include <vector>


int main()
{
	Subject *ps = new ConcreteSubject();
	Observer *poa = new ConcreteObserver("A");
	Observer *pob = new ConcreteObserver("B");

	ps->attach(poa);
	ps->attach(pob);

	ps->setState(1);
	ps->notify();

	ps->detach(pob);
	ps->setState(2);
	ps->notify();

	ps->getState();

	delete ps;
	delete poa;
	delete pob;

	return 0;
}
