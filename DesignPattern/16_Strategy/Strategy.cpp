// Design Pattern
// Mediator.cpp
// 2019.08.28

#include "Context.h"
#include "Strategy.h"


int main()
{
	Context *pc = new Context();
	Strategy *psa = new ConcreteStrategyA();
	Strategy *psb = new ConcreteStrategyB();

	pc->setStrategy(psa);
	pc->algorithm();

	pc->setStrategy(psb);
	pc->algorithm();

	delete pc;
	delete psa;
	delete psb;

	return 0;
}
