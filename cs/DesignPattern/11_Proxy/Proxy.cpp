// Design Pattern
// Proxy.cpp
// 2019.08.28

#include <iostream>
#include <string>
#include <map>


class Subject
{
public:
	virtual void request() {}
};


class RealSubject
{
public:
	void request() {
		std::cout << "RealSubject::request()" << std::endl;
	}
};


class Proxy: public Subject
{
public:
	Proxy() {
		prs = new RealSubject();
	}
	void preRequest() {
		std::cout << "Proxy::preRequest()" << std::endl;
	}
	void afterRequest() {
		std::cout << "Proxy::afterRequest()" << std::endl;
	}
	void request() {
		preRequest();
		prs->request();
		afterRequest();
	}
	virtual ~Proxy() {
		delete prs;
	}

private:
	RealSubject *prs;
};


int main()
{
	Proxy proxy;
	proxy.request();

	return 0;
}
