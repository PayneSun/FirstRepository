// ch18_tools_for_lagre_programs
// multi_inheritance.cpp
// 2019/6/25


#include <iostream>


class ZooAnimal;
class Endangered;

class Bear: public ZooAnimal {};

class Panda: public Bear, public Endangered {};


int main()
{
	//

	return 0;
}
