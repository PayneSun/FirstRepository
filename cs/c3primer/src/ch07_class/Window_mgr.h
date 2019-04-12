// ch07_class.cpp
// Window_mgr.h
// 2019/4/12

#include "Screen.h"

#include <vector>
#include <string>


class Window_mgr {
private:
	std::vector<Screen> screens{ Screen(24, 80, ' ') };
};


inline Screen &Screen::move(pos r, pos c)
{
	pos row = r * this->width;
	this->cursor = row + c;

	return *this;
}


inline char Screen::get(pos r, pos c) const
{
	pos row = r * this->width;

	return this->contents[row + c];
}


void Screen::some_member() const
{
	++this->access_ctr;
}
