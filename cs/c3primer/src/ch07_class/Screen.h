// ch07_class.cpp
// Screen.h
// 2019/4/12

#include <iostream>
#include <istream>
#include <string>


class Screen {
public:
	typedef std::string::size_type pos;
	//using pos = std::string::size_type;
	Screen() = default;
	Screen(pos ht, pos wd, char c): height(ht), width(wd), contents(ht * wd, c)
	{
	}
	char get() const
	{
		return this->contents[cursor];
	}
	inline char get(pos ht, pos wd) const;
	Screen &move(pos r, pos c);
	void some_member() const;
private:
	pos cursor = 0;
	pos height = 0, width = 0;
	std::string contents;
	mutable std::size_t access_ctr;
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
