// ch07_class.cpp
// Sales_data.h
// 2019/4/11


#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <sstream>

// The definition of class Sales_data
class Sales_data {
friend Sales_data add(const Sales_data&, const Sales_data&);
friend std::istream &read(std::istream&, Sales_data&);
friend std::ostream &print(std::ostream&, const Sales_data&);

public:
	Sales_data() = default;
	Sales_data() : Sales_data("", 0, 0)
	{
	}
	Sales_data(std::string s) : Sales_data(s, 0, 0)
	{
	}
	explicit Sales_data(const std::string &s) : bookNo(s)
	{
	}
	Sales_data(const std::string &s, unsigned n, double p) :
		       bookNo(s), units_sold(n), revenue(p * n)
	{
	}
	explicit Sales_data(std::istream &);

    std::string isbn() const
    {
    	return this->bookNo;
    }
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

#endif //SALES_DATA_H
