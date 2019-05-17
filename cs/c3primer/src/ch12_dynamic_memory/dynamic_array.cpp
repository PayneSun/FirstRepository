// ch12_dynamic_memory
// dynamic_array.cpp
// 2019.05.11


#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <memory>
#include <new>


int main()
{
	typedef int arrT[42];
	int *p = new arrT;

	int *pia = new int[10];
	int *pia2 = new int[10]();

	std::string *psa = new std::string[10];
	std::string *psa2 = new std::string[10]();

	std::unique_ptr<int[]> up(new int[10]);
	up.release();

	std::shared_ptr<int> sp(new int[10], [](int *p){ delete [] p;});
	sp.reset();

	std::allocator<std::string> alloc;
	auto const pa = alloc.allocate(5);

}
