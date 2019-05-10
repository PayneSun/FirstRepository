// ch12_dynamic_memory
// unique_ptr.cpp
// 2019.05.10


#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <memory>
#include <new>


int main()
{
	std::unique_ptr<double> p1;
	std::unique_ptr<int> p2(new int(42));
	std::unique_ptr<std::string> p3(new std::string("Stegosaurus"));

	std::unique_ptr<std::string> p4(p3.release());
	std::unique_ptr<std::string> p5(new std::string("Trex"));
	p4.reset(p5.release());

}
