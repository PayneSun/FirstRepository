// ch15_object_oriented_programming
// oop_intro.cpp
// 2019/6/2


#include <iostream>
#include <sstream>
#include <memory>
#include <set>
#include <algorithm>


class Quote {
public:
	std::string isbn() const;
	virtual double net_price(std::size_t n) const;
};


class Bulk_quote : public Quote {
public:
	double net_price(std::size_t) const override;
};


double print_total(std::ostream &os, const Quote &item, std::size_t n) {
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn() << " # sold: " << n
	   << " total due: " << ret << std::endl;
	return ret;
}
