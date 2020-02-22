// ch19_specialized_tools_and_techniques
// enum.cpp
// 2019/6/27


#include <iostream>
#include <typeinfo>


enum class open_modes {input, output, append};
enum color {red, yellow, green};
enum {floatPrec = 5, doublePrec = 10, doubleDoublePrec = 10};

enum Tokens {INLINE = 128, VIRTUAL = 129};

void ff(Tokens) { std::cout << __LINE__ << std::endl; }
void ff(int) { std::cout << __LINE__ << std::endl; }

int main()
{
	Tokens curTok = INLINE;
	ff(128);
	ff(INLINE);
	ff(curTok);

	return 0;
}
