// ch16_templates_and_generic_programming
// define_template.cpp
// 2019/6/6


#include <iostream>
#include <cstring>
#include <memory>
#include <functional>


template<typename T> inline T m_min(const T&, const T&);
template<typename T> constexpr T m_max(const T&, const T&);


template <typename T>
int compare(const T &v1, const T &v2)
{
	if (v1 < v2) {
		return -1;
	}
	if (v2 < v1) {
		return 1;
	}
	return 0;
}


template<unsigned N, unsigned M>
int compare(const char (&p1)[N], const char (&p2)[M])
{
	return strcmp(p1, p2);
}


template <typename T, typename F = std::less<T>>
int compare(const T &v1, const T &v2, F f = F())
{
	if (f(v1, v2)) { return -1; }
	if (f(v2, v1)) { return 1; }
	return 0;
}


template <class T = int>
class Numbers
{
public:
	Numbers(T v = 0): val(v) {}
private:
	T val;
};


int main()
{
	Numbers<long double> lots_of_precision;
	Numbers<> average_precision;

	return 0;
}
