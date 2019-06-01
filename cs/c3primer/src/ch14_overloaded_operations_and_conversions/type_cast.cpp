// ch14_overloaded_operations_and_conversions
// type_cast.cpp
// 2019/6/1


#include <iostream>
#include <map>
#include <functional>


class SmallInt
{
public:
	SmallInt(int i = 0): val(i) {
		if (i < 0 || i > 255) {
			throw std::out_of_range("Bad SmallInt value.");
		}
	}
	explicit operator int() const { return val; }
private:
	std::size_t val;
};


int main()
{
	SmallInt si = 3;
//	si + 3; // error
	static_cast<int>(si) + 3;

	return 0;
}
