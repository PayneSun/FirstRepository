// Design Pattern
// State.cpp
// 2019.08.30

#include "State.h"
#include "Context.h"

#include <iostream>


int main()
{
	Context *pc = new Context();
	pc->request();
	pc->request();
	pc->request();

	delete pc;

	return 0;
}
