// example_201.cpp
//
// 2019.08.22

#include <iostream>


class A
{
public:
	A(int n) { value = n; }
//	A(A other) { value = other.value; }
	A(const A &other) { value = other.value; }
	void Print() { std::cout << value << std::endl; }
private:
	int value;
};


int main()
{
	A a = 10;
	A b = a;
	b.Print();

	return 0;
}
