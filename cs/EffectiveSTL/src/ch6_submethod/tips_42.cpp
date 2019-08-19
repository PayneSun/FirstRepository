// 第42条：确保less<T>与operator<具有相同的语义
//
// tips_42.cpp
// 2019/8/19

#include <iostream>
#include <set>


class Widget
{
public:
	std::size_t weight() const;
	std::size_t maxSpeed() const;
};


struct MaxSpeedCompare: public std::binary_function<Widget, Widget, bool>
{
	bool operator()(const Widget& lhs, const Widget& rhs) {
		return lhs.maxSpeed() < rhs.maxSpeed();
	}
};


int main()
{
	std::multiset<Widget, MaxSpeedCompare> widgets;

	return 0;
}

