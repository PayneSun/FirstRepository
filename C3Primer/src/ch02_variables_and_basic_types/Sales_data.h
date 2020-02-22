// ch02_variables_and_basic_types
// Sales_data.h
// 2019/3/22


#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <string>

struct Sales_data {
	std::string bookNo;
	unsigned unit_sold = 0;
	double revenue = 0.0;
};

#endif
