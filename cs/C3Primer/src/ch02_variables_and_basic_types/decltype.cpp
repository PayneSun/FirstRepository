// ch02_variables_and_basic_types
// decltype.cpp
// 2019/3/22

int main()
{
	int i = 42, *p = &i, &r = i;
	decltype(r+0) b;
	decltype(*p) c;
}
