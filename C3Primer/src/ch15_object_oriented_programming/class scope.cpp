// ch15_object_oriented_programming
// class_scope.cpp
// 2019/6/5


#include <iostream>


struct Base{
	int memfcn();
};


struct Derived: Base {
	int memfcn(int);
};

int main()
{
	Derived d;
	Base b;
	b.memfcn();
	d.memfcn(10);
//	d.memfcn();
	d.Base::memfcn();

	return 0;
}
