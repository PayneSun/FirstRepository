// ch13_copy_control
// source.cpp
// 2017/5/3

#include <iostream>
#include <algorithm>

using namespace std;


int main() {
	std::cout << "chapter 13 copy control" << std::endl;

	return 0;
}


struct NoCopy {
	NoCopy() = default;
	NoCopy(const NoCopy&) = delete;
	NoCopy& operator=(const NoCopy&) = delete;
	~NoCopy() = default;
};


class HasPtr {
public:
	friend void swap(HasPtr&, HasPtr&);

	HasPtr(const string &s = string()) : ps(new string(s)), i(0) {}
	HasPtr(const HasPtr &p) : ps(new string(*p.ps)), i(p.i) {}
	HasPtr& operator=(const HasPtr&);
	~HasPtr() { delete ps; }

private:
	string *ps;
	int i;
};


HasPtr& HasPtr::operator=(const HasPtr &rhs) {
	auto newp = new string(*rhs.ps);
	delete ps;
	ps = newp;
	i = rhs.i;
	return *this;
}


inline void swap(HasPtr &lhs, HasPtr &rhs) {
	using std::swap;
	std::swap(lhs.ps, rhs.ps);
	std::swap(lhs.i, rhs.i);
}


class StrVec {
public:
	StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
	StrVec(const StrVec&);
	StrVec &operator=(const StrVec&);
	~StrVec();
	void push_back(const string&);
	size_t size() const { return first_free - elements; }
	size_t capacity() const { return cap - elements; }
	string* begin() const { return elements; }
	string* end() const { return first_free; }

private:
	static allocator<string> alloc;
	void chk_n_alloc() { if (size() == capacity()) reallocate(); }
	pair<string*, string*> alloc_n_copy(const string*, const string*);
	void free();
	void reallocate();
	string *elements;
	string *first_free;
	string *cap;
};


void StrVec::push_back(const string& s) {
	chk_n_alloc();
	alloc.construct(first_free++, s);
}


pair<string*, string*> StrVec::alloc_n_copy(const string *b, const string *e) {
	auto data = alloc.allocate(e - b);

	return { data, uninitialized_copy(b, e, data) };
}


void StrVec::free() {
	if (elements) {
		for (auto p = first_free; p != elements;) {
			alloc.destroy(--p);
		}
		alloc.deallocate(elements, cap - elements);
	}
}


StrVec::StrVec(const StrVec &s) {
	auto newdata = alloc_n_copy(s.begin(), s.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}


StrVec::~StrVec() {
	free();
}


StrVec &StrVec::operator=(const StrVec &rhs) {
	auto data = alloc_n_copy(s.begin(), s.end());
	elements = data.first;
	first_free = cap = data.second;

	return *this;
}


void StrVec::reallocate() {
	auto newcapacity = size() ? 2 * size() : 1;
	auto newdata = alloc.allocate(newcapacity);
	auto dest = newdata;
	auto elem = elements;
	0
	for (size_t i = 0; i != size(); ++i) {
		alloc.construct(dest++, std::move(*elem++));
	}
	free();
	elements = newdata;
	first_free = dest;
	cap = elements + newcapacity;
}
