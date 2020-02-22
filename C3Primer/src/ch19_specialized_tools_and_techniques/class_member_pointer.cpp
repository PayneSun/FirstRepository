// ch19_specialized_tools_and_techniques
// class_member_pointer.cpp
// 2019/6/27


#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <algorithm>


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


Screen::Action Screen::Menu[] = {
	&Screen::home, &Screen::forward, &Screen::back, &Screen::up, &Screen::down
};


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

	std::vector<std::string*> pvec;
	std::function<bool (const std::string*)> fp = &std::string::empty;
	std::find_if(pvec.begin(), pvec.end(), fp);

	std::vector<std::string> svec;
	std::find_if(svec.begin(), svec.end(), std::mem_fn(&std::string::empty));
	std::find_if(svec.begin(), svec.end(), std::bind(&std::string::empty, std::placeholders::_1));

	return 0;
}
