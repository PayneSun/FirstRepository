// ch12_dynamic_memory
// str_blob_ptr.h
// 2019.05.10


#include "str_blob.h"

#include <iostream>
#include <string>
#include <vector>
#include <memory>

class StrBlob;

class StrBlobPtr {
public:
	StrBlobPtr(): curr(0) {}
	StrBlobPtr(StrBlob &a, std::size_t sz = 0): wptr(a.data), curr(sz) {}
	std::string& deref() const;
	StrBlobPtr& incr();

private:
	std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string &) const;
	std::weak_ptr<std::vector<std::string>> wptr;
	std::size_t curr;
};


std::shared_ptr<std::vector<std::string>>
StrBlobPtr::check(std::size_t i, const std::string &msg) const {
	auto ret = this->wptr.lock();
	if (!ret) {
		throw std::runtime_error("unbound StrBlobPtr");
	}
	if (i >= ret->size()) {
		throw std::out_of_range(msg);
	}

	return ret;
}


std::string& StrBlobPtr::deref() const {
	auto p = this->check(this->curr, "dereference past end");
	return (*p)[this->curr];
}


StrBlobPtr& StrBlobPtr::incr() {
	check(this->curr, "increment past end of StrBlobPtr");
	++this->curr;
	return *this;
}
