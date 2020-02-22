


#include <iostream>


typedef int length;

class Point3d {
public:
	void foo(length val) { _val = val; }
	length foo() {return _val; }
private:
	typedef float length;
	length _val;
};


int main()
{
	Point3d p3d;

	p3d.foo(5.6);

	std::cout << p3d.foo() << std::endl;

	return 0;
}
