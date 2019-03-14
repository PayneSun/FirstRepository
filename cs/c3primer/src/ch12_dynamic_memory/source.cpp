// ch12_dynamic_memory
// ch12_example.cpp
// 2017.05.02

/*
#include <iostream>
#include <memory>
#include <list>
#include <vector>

#include "ch12_define.h"

using namespace std;


int main() {

	// smart pointer
	shared_ptr<string> p1;
	shared_ptr<list<int>> p2;
	if (p1 && p1->empty()) {
		*p1 = "Hi";
	}

	shared_ptr<int> p3 = make_shared<int>(42);
	auto p6 = make_shared<vector<string>>();
	int *pi = new int;

	auto lambda = [](int p) { return shared_ptr<int>(new int(p)); };

	unique_ptr<double> up1;
	unique_ptr<int> up2(new int(42));

	auto p = make_shared<int>(42);
	weak_ptr<int> wp(p);

	int *pia = new int[10];
	int *pia2 = new int[10]();
	delete[] pia;
	delete[] pia2;

	unique_ptr<int[]> up(new int[10]);
	up.release();
	shared_ptr<int> sp(new int[10], [](int *p) { delete[] p; });
	sp.reset();

	allocator<string> alloc;
	auto const p = alloc.allocate(5);

	return 0;
}
*/
