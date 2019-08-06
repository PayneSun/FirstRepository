// ch07_class.cpp
// define.h
// 2017/4/17

#ifndef CP_CH7_CP_CH7_DEFINE_H_
#define CP_CH7_CP_CH7_DEFINE_H_

#include <iostream>
#include <fstream>
#include <ostream>
#include <vector>


// The definition of class Screen
class Screen {
friend class Window_mgr;

public:
	typedef std::string::size_type pos;

	Screen() = default;
	Screen(pos ht, pos wd, char c) :
		height(ht), width(wd), contents(ht * wd, c) {}

	char get() const { return contents[cursor]; }
	Screen &display(std::ostream &os)
		{ do_display(os); return *this; }
	const Screen &display(std::ostream &os) const
		{ do_display(os); return *this; }
	inline char get(pos ht, pos wd) const;
	Screen &move(pos r, pos c);
	void some_member() const;
	Screen &set(char);
	Screen &set(pos, pos, char);

private:
	mutable size_t access_ctr;
	pos cursor = 0;
	pos height = 0, width = 0;
	std::string contents;

	void do_display(std::ostream &os) const { os << contents; }
};

char Screen::get(pos r, pos c) const
{
	pos row = r * width;
	return contents[row + c];
}


// The definition of class Window_mgr
class Window_mgr {
public:
	using ScreenIndex = std::vector<Screen>::size_type;
	void clear(ScreenIndex);
	ScreenIndex addScreen(const Screen&);

private:
	std::vector<Screen> screens{Screen(24, 80, ' ')};
};


// The definition of class Debug
class Debug {
public:
	constexpr Debug(bool b = true): hw(b), io(b), other(b) {}
	constexpr Debug(bool h, bool i, bool o): hw(h), io(i), other(o) {}
	constexpr bool any() { return hw || io || other; }

	void set_io(bool b) { io = b; }
	void set_hw(bool b) { hw = b; }
	void set_other(bool b) { other = b; }

private:
	bool hw;
	bool io;
	bool other;
};


// The definition of class Account
class Account {
public:
	void calculate() { amount += amount * interestRate; }
	static double rate() { return interestRate; }
	static void rate(double);

private:
	std::string owner;
	double amount;
	static double interestRate;
	static double initRate();
};


#endif /* CP_CH7_CP_CH7_DEFINE_H_ */
