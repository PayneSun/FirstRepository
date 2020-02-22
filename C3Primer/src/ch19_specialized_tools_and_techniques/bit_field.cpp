// ch19_specialized_tools_and_techniques
// bit_field.cpp
// 2019/6/28


#include <iostream>
#include <typeinfo>


typedef unsigned int Bit;
class File {
	Bit mode: 2;
	Bit modified: 1;
	Bit prot_owner: 3;
	Bit prot_group: 3;
	Bit prot_world: 3;
public:
	enum modes { READ = 01, WRITE = 02, EXECUTE = 03 };
	File& open(modes);
	void close();
	void write();
	bool isRead() const;
	void setWrite();
};


void File::write()
{
	modified = 1;
}


void File::close()
{
	//
}


File& File::open(File::modes m)
{
	//
	return *this;
}


inline bool File::isRead() const
{
	return mode & READ;
}


inline void File::setWrite()
{
	mode |= WRITE;
}


class Foo
{
public:
	Foo(const volatile Foo&);
	Foo& operator=(volatile const Foo&);
	Foo& operator=(volatile const Foo&) volatile;
};


void (*pf1)(int);
extern "C" void (*pf2)(int);


int main()
{
	//
	volatile int v;
	int* volatile vip;
	volatile int *ivp;
	volatile int* volatile vivp;

	ivp = &v;
	vivp = &v;

	return 0;
}
