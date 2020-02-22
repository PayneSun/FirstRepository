// ch15_object_oriented_programming
// container_and_inherit.cpp
// 2019/6/5


#include <iostream>
#include <memory>
#include <set>


class Quote;
class Disc_quote;
class Bulk_quote;


class Basket {
public:
	void add_item(const std::shared_ptr<Quote> &sale) {
		items.insert(sale);
	}
	void add_tem(const Quote& sale) {
		items.insert(std::shared_ptr<Quote>(sale.clone()));
	}
	void add_tem(Quote&& sale) {
		items.insert(std::shared_ptr<Quote>(std::move(sale).clone()));
	}
	double total_receipt(std::ostream &) const;
private:
	static bool compare(const std::shared_ptr<Quote> &lhs,
						const std::shared_ptr<Quote> &rhs) {
		return lhs->isbn() < rhs->isbn();
	}
	std::multiset<std::shared_ptr<Quote>, decltype(compare)*> items{};
};


double print_total(std::ostream &os, const Quote &item, std::size_t n) {
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn()
		<< " # sold: " << n << " total due: " << ret << std::endl;
	return ret;
}


double Basket::total_receipt(std::ostream &os) const {
	double sum = 0.0;
	for (auto iter = items.cbegin();
			  iter != items.cend();
			  iter = items.upper_bound(*iter)) {
		sum += print_total(os, **iter, items.count(*iter));
	}
	os << "Total Sale: " << sum << std::endl;
	return sum;
}


int main()
{
	return 0;
}
