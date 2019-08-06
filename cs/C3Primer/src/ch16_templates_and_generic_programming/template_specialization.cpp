// ch16_templates_and_generic_programming
// template_specialization.cpp
// 2019/6/12


#include <iostream>
#include <string>
#include <cstring>


template <typename T>
int compare(const T &, const T &)
{
	return 0;
}


template<>
int compare(const char* const &p1, const char* const &p2)
{
	return strcmp(p1, p2);
}


int main()
{
	//

	return 0;
}

