// ch12_dynamic_memory
// weak_ptr.cpp
// 2019.05.10


#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <memory>
#include <new>


int main()
{
	auto p = std::make_shared<int>(42);
	std::weak_ptr<int> wp(p);
	if (std::shared_ptr<int> np = wp.lock()) {
		std::cout << *np << std::endl;
	}
}
