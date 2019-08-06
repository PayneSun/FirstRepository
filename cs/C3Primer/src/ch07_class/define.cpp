// ch07_class.cpp
// define.cpp
// 2017/2/11


#include "define.h"
#include <iostream>
#include <istream>
#include <string>





//
//
inline Screen &Screen::move(pos r, pos c) {
	pos row = r * width;
	cursor = row + c;
	return *this;
}


//
//
void Screen::some_member() const {
	++access_ctr;
}


//
//
inline Screen &Screen::set(char c) {
	contents[cursor] = c;
	return *this;
}


//
//
inline Screen &Screen::set(pos r, pos col, char ch) {
	contents[r*width + col] = ch;
	return *this;
}


//
//
void Window_mgr::clear(ScreenIndex i) {
	Screen &s = screens[i];
	s.contents = std::string(s.height * s.width, ' ');
}


//
//
Window_mgr::ScreenIndex Window_mgr::addScreen(const Screen &s) {
	screens.push_back(s);
	return screens.size() - 1;
}


//
//
void Account::rate(double newRate) {
	interestRate = newRate;
}


//
//
std::ostream &operator<<(std::ostream &os, const Sales_data &item) {
	os << item.isbn() << " " << item.units_sold << " "
		<< item.revenue << " " << item.avg_price();

	return os;
}


//
//
std::istream &operator >> (std::istream &is, Sales_data &item) {
	double price;
	is >> item.bookNo >> item.unit_sold >> price;
	if (is) {
		item.revenue = item.unit_sold * price;
	}
	else {
		item = Sales_data();
	}

	return is;
}


//
//
Sales_data operator+(const Sales_data &lhs, const Sales_data & rhs) {
	Sales_data sum = lhs;
	sum += rhs;
	return sum;
}


//
//
bool operator==(const Sales_data &lhs, const Sales_data &rhs) {
	return lhs.isbn() == rhs.isbn() &&
		lhs.unit_sold == rhs.unit_sold &&
		lhs.revenue == rhs.revenue;
}


//
//
bool operator!=(const Sales_data &lhs, const Sales_data &rhs) {
	return !(lhs == rhs);
}
