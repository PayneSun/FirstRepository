// ch07_class.cpp
// define.h
// 2017/4/17

#ifndef CP_CH7_CP_CH7_DEFINE_H_
#define CP_CH7_CP_CH7_DEFINE_H_

#include <iostream>
#include <fstream>
#include <ostream>
#include <vector>


// The definition of class Sales_data
class Sales_data {
friend Sales_data add(const Sales_data&, const Sales_data&);
friend std::istream &read(std::istream&, Sales_data&);
friend std::ostream &print(std::ostream&, const Sales_data&);

public:
	Sales_data() = default;
	explicit Sales_data(const std::string &s) : bookNo(s) {}
	Sales_data(const std::string &s, unsigned n, double p) :
		       bookNo(s), units_sold(n), revenue(p * n) {}
	explicit Sales_data(std::istream &);

    std::string isbn() const { return bookNo; }
    Sales_data& combine(const Sales_data&);

private:
    double avg_price() const;

    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

// The declaration of class Sales_data's interfaces
Sales_data add(const Sales_data&, const Sales_data&);
std::istream &read(std::istream&, Sales_data&);
std::ostream &print(std::ostream&, const Sales_data&);
std::ostream &operator<<(std::ostream &os, const Sales_data &item);
std::istream &operator>>(std::istream &os, Sales_data &item);
Sales_data operator+(const Sales_data &lhs, const Sales_data & rhs);
bool operator==(const Sales_data &lhs, const Sales_data &rhs);


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
