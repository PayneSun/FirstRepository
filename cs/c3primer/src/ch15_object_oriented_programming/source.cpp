// ch15_object_oriented_programming
// source.cpp
// 2018/10/24


#include <iostream>
#include <sstream>
#include <memory>
#include <set>
#include <algorithm>


//
class Quote {
public:
	Quote() = default;
	Quote(const std::string &book, double sales_price) :
		bookNo(book), price(sales_price) {}
	virtual Quote* clone() const & { return new Quote(*this); }
	virtual Quote* clone() && { return new Quote(std::move(*this)); }

	std::string isbn() const;
	virtual double net_price(std::size_t n) const { return n * price; }
	virtual ~Quote() = default;
private:
	std::string bookNo;
protected:
	double price = 0.0;
};


//
class Disc_quote : public Quote {
public:
	Disc_quote() = default;
	Disc_quote(const std::string &book, double price, std::size_t qty, double disc) :
		Quote(book, price), quantity(qty), discount(disc) {}
	double net_price(std::size_t) const = 0;
protected:
	std::size_t quantity = 0;
	double discount = 0.0;
};


//
class Bulk_quote : public Disc_quote {
public:
	Bulk_quote() = default;
	Bulk_quote(const std::string &book, double price, std::size_t qty, double disc) :
		Disc_quote(book, price, qty, disc) {}
	double net_price(std::size_t) const override;
};


//
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


//
double Bulk_quote::net_price(std::size_t cnt) const {
	if (cnt >= quantity) {
		return cnt * (1 - discount) * price;
	}
	else {
		return cnt * price;
	}
}


//
double print_total(std::ostream &os, const Quote &item, std::size_t n) {
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn()
		<< " # sold: " << n << " total due: " << ret << std::endl;
	return ret;
}


//
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


//
class Query_base {
	friend class Query;
protected:
	using line_no = TextQuery::line_no;
	virtual ~Query_base() = default;
private:
	virtual QueryResult eval(const TextQuery &) const = 0;
	virtual std::string rep() const = 0;
};


//
class Query {
	friend Query operator~(const Query &);
	friend Query operator|(const Query &, const Query &);
	friend Query operator&(const Query &, const Query &);
public:
	Query(const std::string &);
	QueryResult eval(const TextQuery &t) const { return q->eval(t); }
	std::string rep() const { return q->rep(); }
private:
	Query(std::shared_ptr<Query_base> query) : q(query) {}
	std::shared_ptr<Query_base> q;
};


//
std::ostream & operator<<(std::ostream &os, const Query &query) {
	return os << query.rep();
}


//
class WordQuery : public Query_base {
	friend class Query;
	WordQuery(const std::string &s) : query_word(s) {}
	QueryResult eval(const TextQuery &t) const {
		return t.query(query_word);
	}
	std::string rep() const { return query_word; }
	std::string query_word;
};


//
inline Query::Query(const std::string &s) : q(new WordQuery(s)) {}


//
class NotQuery : public Query_base {
	friend Query operator~(const Query &s);
	NotQuery(const Query &q) : query(q) {}
	std::string rep() const { return "~(" + query.rep() + ")"; }
	QueryResult eval(const TextQuery &) const;
	Query query;
};


//
inline Query operator~(const Query &operand) {
	return std::shared_ptr<Query_base>(new NotQuery(operand));
}


//
class BinaryQuery : public Query_base {
protected:
	BinaryQuery(const Query &l, const Query &r, std::string s) :
		lhs(l), rhs(r), opSym(s) {}
	std::string rep() const {
		return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")";
	}
	Query lhs, rhs;
	std::string opSym;
};


//
class AndQuery : public BinaryQuery {
	friend Query operator&(const Query &, const Query &);
	AndQuery(const Query &left, const Query &right) : BinaryQuery(left, right, "&") {}
	QueryResult eval(const TextQuery &) const;
};


//
inline Query operator&(const Query &lhs, const Query &rhs) {
	return std::shared_ptr<Query_base>(new AndQuery(lhs, rhs));
}


//
class OrQuery : public BinaryQuery {
	friend Query operator|(const Query &, const Query &);
	OrQuery(const Query &left, const Query &right) : BinaryQuery(left, right, "|") {}
	QueryResult eval(const TextQuery &) const;
};


//
inline Query operator|(const Query &lhs, const Query &rhs) {
	return std::shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}


//
QueryResult OrQuery::eval(const TexQuery &text) const {
	auto right = rhs.eval(text), left = lhs.eval(text);
	auto ret_lines = std::make_shared<std::set<line_no>>(left.begin(), left.end());
	ret_lines->insert(right.begin(), right.end());
	return QueryResult(rep(), ret_lines, left.get_file());
}


//
QueryResult AndQuery::eval(const TextQuery &text) const {
	auto left = lhs.eval(text), right = rhs.eval(text);
	auto ret_lines = std::make_shared<std::set<line_no>>();
	std::set_intersection(left.begin(), left.end(),
						  right.begin(), right.end(), std::inserter(*ret_lines, ret_lines->begin()));
	return QueryResult(rep(), ret_lines, left.get_file());
}


//
QueryResult NotQuery::eval(const TextQuery &text) const {
	auto result = query.eval(text);
	auto ret_lines = std::make_shared<std::set<line_no>>();
	auto beg = result.begin(), end = result.end();
	auto sz = result.get_file()->size();
	for (std::size_t n = 0; n != sz; ++n) {
		if (beg == end || *beg != n) {
			ret_lines->insert(n);
		} else if (beg != end) {
			++beg;
		}
	}
	return QueryResult(rep(), ret_lines, result.get_file());
}
