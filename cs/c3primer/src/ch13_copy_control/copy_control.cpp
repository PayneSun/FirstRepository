// ch13_copy_control
// copy_control.cpp
// 2019/5/16

#include <iostream>
#include <algorithm>


struct NoCopy{
	NoCopy() = default;
	NoCopy(const NoCopy&) = delete;
	NoCopy &operator=(const NoCopy&) = delete;
	~NoCopy() = default;
};


class PrivateCopy{
	PrivateCopy(const PrivateCopy&);
	PrivateCopy &operator=(const PrivateCopy&);
public:
	PrivateCopy() = default;
	~PrivateCopy();
};


int main() {
	//
	return 0;
}
