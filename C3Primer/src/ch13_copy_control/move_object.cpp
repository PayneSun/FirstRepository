// ch13_copy_control
// move_object.cpp
// 2019/5/28

#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>


class Foo {
public:
	Foo sorted() &&;
	Foo sorted() const &;
	Foo& operator=(const Foo&) &;  //只能向可修改的左值赋值
	Foo anotherMem() const &;

private:
	std::vector<int> data;
};


Foo& Foo::operator=(const Foo &rhs) &
{
	return *this;
}


Foo Foo::sorted() &&
{
	std::sort(data.begin(), data.end());
	return *this;
}


Foo Foo::sorted() const &
{
	Foo ret(*this);
//	std::sort(ret.data.begin(), ret.data.end());
//	return ret;
	return ret.sorted();
}


int main()
{
	Foo foo;

	return 0;
}
