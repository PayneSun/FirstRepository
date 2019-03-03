// ch16_templates_and_generic_programming
// ch16_example.cpp
// 2018.11.13


#include <iostream>
#include <cstring>
#include <memory>


using namespace std;


//
template <typename T>
int compare(const T &v1, const T &v2) {
	if (v1 < v2) {
		return -1;
	}
	if (v2 < v1) {
		return 1;
	}
	return 0;
}


//
template<unsigned N, unsigned M>
int compare(const char(&p1)[N], const char(&p1)[M]) {
	return strcmp(p1, p2);
}


//
template <typename T> class Blob {
public:
	typedef T value_type;
	typedef typename std::vector<T>::size_type size_type;
	Blob();
	Blob(std::initializer_list<T> il);
	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }
	void push_back(const T &t) { data->push_back(t); }
	void pop_back();
	T& back();
	T& operator[](size_type i);
private:
	std::shared_ptr<std::vector<T>> data;
	void check(size_type i, const std::string &msg) const;
};


//
template <typename T>
void Blob<T>::check(std::size_type i, const std::string &msg) const {
	if (i >= data->size()) {
		throw std::out_of_range(msg);
	}
}


//
template <typename T>
T& Blob<T>::back() {
	check(0, "back on empty Blob");
	return data->back();
}


//
template <typename T>
T& Blob<T>::operator[](size_type i) {
	check(i, "subscript out of range");
	return (*data)[i];
}


//
template <typename T>
Blob<T>::Blob() : data(std::make_shared<std::vector<T>>()) {
}


//
template <typename T>
Blob<T>::Blob(std::initializer_list<T> il) : data(std::make_shared<std::vector<T>>(il)) {
}


//
template <typename T> class BlobPtr {
public:
	BlobPtr() : curr(0) {}
	BlobPtr(Blob<T> &a, std::size_t sz = 0) : wptr(a.data), curr(sz) {}
	T& operator*() const {
		auto p = check(curr, "dereference past end");
		return (*p)[curr];
	}
	BlobPtr& operator++();
	BlobPtr& operator--();
private:
	std::shared_ptr<std::vector<T>> check(std::size_t, const std::string &) const;
	std::weak_ptr<std::vector<T>> wptr;
	std::size_t curr;
};


//
template <typename T>
BlobPtr<T> BlobPtr<T>::operator++(int) {
	BlobPtr ret = *this;
	++*this;
	return ret;
}


//
template<class T = int>
class Numbers {
public:
	Numbers(T v = 0) : val(v) {}
private:
	T val;
};


//
class DebugDelete {
public:
	DebugDelete(std::ostream &s = std::cerr) : os(s) {}
	template<typename T> void operator()(T *p) const {
		os << "deleting unique_ptr" << std::endl;
		delete p;
	}
private:
	std::ostream &os;
};


//
template <typename F, typename T1, typename T2>
void flip1(F f, T1 t1, T2 t2) {
	f(t2, t1);
}

void f(int v1, int &v2) {
	cout << v1 << " " << ++v2 << endl;
}

