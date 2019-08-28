// Design Pattern
// Command.cpp
// 2019.08.28

#include <iostream>
#include <string>
#include <map>


class Receiver
{
public:
	void action() {
		std::cout << "Receiver::action()" << std::endl;
	}
};


class Command
{
public:
	virtual void execute() {}
};


class ConcreteCommand: public Command
{
public:
	ConcreteCommand(Receiver *pr): pr(pr) {}
	void execute() {
		std::cout << "ConcreteCommand::execute()" << std::endl;
		pr->action();
	}
	~ConcreteCommand() {
		delete pr;
	}
private:
	Receiver *pr;
};


class Invoker
{
public:
	Invoker(Command *pc): pc(pc) {}
	void call() {
		std::cout << "Invoker::call()" << std::endl;
		pc->execute();
	}
	~Invoker() {
		delete pc;
	}
private:
	Command *pc;
};



int main()
{
	Receiver *pr = new Receiver();
	Command *pcc = new ConcreteCommand(pr);
	Invoker *pi = new Invoker(pcc);
	pi->call();

	delete pr;
	delete pcc;
	delete pi;

	return 0;
}
