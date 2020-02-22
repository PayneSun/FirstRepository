// ch19_specialized_tools_and_techniques
// rtti.cpp
// 2019/6/26


#include <iostream>
#include <typeinfo>


class Base {
	friend bool operator==(const Base&, const Base&);
public:
	virtual ~Base();
protected:
	virtual bool equal(const Base&) const;
};


class Derived: public Base {
public:
	virtual ~Derived();
protected:
	bool equal(const Base&) const;
};


bool operator==(const Base &lhs, const Base &rhs)
{
	return typeid(lhs) == typeid(rhs) && lhs.equal(rhs);
}


bool Derived::equal(const Base &rhs) const
{
	auto r = dynamic_cast<const Derived&>(rhs);

	return true;
}


bool Base::equal(const Base &rhs) const
{
	return true;
}


void fun1(Base *pb)
{
	if (Derived *pd = dynamic_cast<Derived*>(pb)) {
		//
	} else {
		//
	}
}


void fun2(const Base &rb)
{
	try {
		const Derived &rd = dynamic_cast<const Derived&>(rb);
	} catch (std::bad_cast &bc) {
		//
	}
}


int main()
{
	std::cout << "ch19_specialized_tools_and_techniques" << std::endl;

	Derived *dp = new Derived;
	Base *bp = dp;

	if (typeid(*bp) == typeid(*dp)) {
		std::cout << __LINE__ << std::endl;
	}

	if (typeid(*bp) == typeid(Derived)) {
		std::cout << __LINE__ << std::endl;
	}

	return 0;
}
