// ch12_dynamic_memory
// associative_container_op.cpp
// 2019.05.08


#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <memory>
#include <new>


int main()
{
	std::shared_ptr<std::string> p1;
	std::shared_ptr<std::list<int>> p2;
	std::shared_ptr<int> p3 = std::make_shared<int>(42);
	std::shared_ptr<std::string> p4 = std::make_shared<std::string>(10, '9');
	std::shared_ptr<int> p5 = std::make_shared<int>();
	auto p6 = std::make_shared<std::vector<std::string>>();

	int *p7 = new int;
	int *p8 = new (std::nothrow) int;

	const int *pci = new const int(1024);
	delete pci;
}
