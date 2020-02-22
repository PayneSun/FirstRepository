// ch13_copy_control
// right_value_ref.cpp
// 2019/5/20

#include <iostream>
#include <utility>

int main() {
	int &&rr1 = 42;
//	int &&rr2 = rr1;
	int &&rr3 = std::move(rr1);

	return 0;
}
