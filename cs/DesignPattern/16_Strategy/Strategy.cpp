// Design Pattern
// Mediator.cpp
// 2019.08.28

#include <iostream>
#include <string>
#include <map>


class Mediator;
class Colleague;


class Mediator
{
public:
	virtual void operation(int id, const std::string &str) {}
	virtual void regist(int id, Colleague *pc) {}
};


class Colleague
{
public:
	virtual void receiveMsg(const std::string &str) {}
	virtual void sendMsg(int, const std::string &str) {}
	void setMediator(Mediator *pm) {
		this->pm = pm;
	}

private:
	Mediator *pm;
};


class ConcreteMediator: public Mediator
{
public:
	void operation(int id, const std::string &str) {
		auto it = pMapIC.find(id);
		if (it == pMapIC.end()) {
			std::cout << "Not found the colleague!" << std::endl;
			return;
		}
		Colleague *pc = it->second;
		pc->receiveMsg(str);
	}
	void regist(int id, Colleague *pc) {
		auto it = pMapIC.find(id);
		if (it == pMapIC.end()) {
			pMapIC.insert(std::make_pair(id, pc));
			pc->setMediator(this);
		}
	}

private:
	std::map<int, Colleague*> pMapIC;
};


class ConcreteColleagueA: public Colleague
{
public:
	void receiveMsg(const std::string &str) {
		std::cout << "Receive message: " << str << std::endl;
	}
	void sendMsg(int id, const std::string &str) {
		std::cout << "Send message from A: " << str << std::endl;
		pm->operation(id, str);
	}

private:
	Mediator *pm;
};


class ConcreteColleagueB: public Colleague
{
public:
	void receiveMsg(const std::string &str) {
		std::cout << "Receive message: " << str << std::endl;
	}
	void sendMsg(int id, const std::string &str) {
		std::cout << "Send message from B: " << str << std::endl;
		pm->operation(id, str);
	}

private:
	Mediator *pm;
};


int main()
{
	Colleague *pcca = new ConcreteColleagueA();
	Colleague *pccb = new ConcreteColleagueB();
	Mediator *pm = new ConcreteMediator();

	pm->regist(1, pcca);
	pm->regist(2, pccb);

	pcca->setMediator(pm);
	pccb->setMediator(pm);

	pcca->sendMsg(2, "hello, i am a");

	std::cout << __LINE__ << std::endl;
	pccb->sendMsg(1, "hello, i am b");
	std::cout << __LINE__ << std::endl;

	delete pcca;
	delete pccb;
	delete pm;

	return 0;
}
