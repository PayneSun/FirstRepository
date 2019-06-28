// ch19_specialized_tools_and_techniques
// local_class.cpp
// 2019/6/28


#include <iostream>
#include <typeinfo>


void foo (int val)
{
	static int si;
	enum Loc {a = 1024, b};
	struct Bar {
		Loc locVal;
		int barVal;
		void fooBar(Loc l = a) {
			barVal = si;
			locVal = b;
		}
	};
};


int main()
{
	//

	return 0;
}
