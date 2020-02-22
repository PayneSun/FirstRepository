// Design Pattern
// Mediator/Subject.h
// 2019.08.28

#ifndef SUBJECT_H
#define SUBJECT_H

#include <iostream>
#include <string>
#include <vector>


class Observer;


class Subject
{
public:
	void attach(Observer *po) {	}
	void detach(Observer *po) {	}
	void notify() {}
	virtual int getState() {}
	virtual void setState(int) {}

private:
	std::vector<Observer*> ovec;
};


class ConcreteSubject: public Subject
{
public:
	void attach(Observer *po) {
		ovec.push_back(po);
	}
	void detach(Observer *po) {
		for (auto it = ovec.begin(); it != ovec.end(); ++it) {
			if (*it == po) {
				ovec.erase(it);
				return;
			}
		}
	}
	void notify() {
		for (auto it = ovec.begin(); it != ovec.end(); ++it) {
			(*it)->update(this);
		}
	}
	int getState() {
		return state;
	}
	void setState(int state) {
		this->state = state;
	}

private:
	int state;
	std::vector<Observer*> ovec;
};

#endif
