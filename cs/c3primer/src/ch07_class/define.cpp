//
// file: ch7_define.cpp
// date: 11/2/2017
//


#include "define.h"
#include <iostream>
#include <istream>
#include <string>


//
//
Sales_data::Sales_data(std::istream &is)
{
	read(is, *this);
}


//
//
double Sales_data::avg_price() const {
	if (units_sold)
		return revenue / units_sold;
	else
		return 0;
}


//
//
Sales_data& Sales_data::combine(const Sales_data &rhs) {
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}


//
//
std::istream &read(std::istream &is, Sales_data &item) {
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
	return is;
}


//
//
std::ostream &print(std::ostream &os, const Sales_data &item) {
    os << item.isbn() << " " << item.units_sold << " "
       << item.revenue << " " << item.avg_price();
    return os;
}


//
//
Sales_data add(const Sales_data &lhs, const Sales_data &rhs) {
	Sales_data sum = lhs;
	sum.combine(rhs);
	return sum;
}


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
