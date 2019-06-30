// ch19_specialized_tools_and_techniques
// union.cpp
// 2019/6/28


#include <iostream>
#include <typeinfo>


union Token {
	char cval;
	int ival;
	double dval;
};


int main()
{
	Token first_token = {'a'};
	Token last_token;
	Token *pt = new Token;

	last_token.cval = 'z';
	pt->ival = 42;

	return 0;
}
