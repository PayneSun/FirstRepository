// ch19_specialized_tools_and_techniques
// class_member_pointer.cpp
// 2019/6/27


#include <iostream>
#include <typeinfo>


class Screen {
public:
	typedef std::string::size_type pos;
	char get_cursor() const { return contents[cursor]; }
	char get() const;
	char get(pos ht, pos wd) const;
	Screen& home();
	Screen& forward();
	Screen& back();
	Screen& up();
	Screen& down();
	using Action = Screen& (Screen::*)();
	enum Directions {HOME, FORWARD, BACK, UP, DOWN};
	static const std::string Screen::*data() { return &Screen::contents; }
	Screen& move(Directions);
private:
	std::string contents;
	pos cursor;
	pos height, width;
	static Action Menu[];
};


Screen& Screen::move(Directions cm)
{
	return (this->*Menu[cm])();
}


Screen::Action Screen::Menu[] = { &Screen::home, &Screen::home, &Screen::home, &Screen::home, };


int main()
{
	const std::string Screen::*pdata;
	pdata = &Screen::contents;

	Screen myScreen, *pScreen = &myScreen;
	auto s = myScreen.*pdata;
	s = pScreen->*pdata;

	auto pmf = &Screen::get_cursor;
	char (Screen::*pmf2)(Screen::pos, Screen::pos) const;
	pmf2 = &Screen::get;

	char c1 = (pScreen->*pmf)();
	char c2 = (myScreen.*pmf2)(0,0);

	return 0;
}
