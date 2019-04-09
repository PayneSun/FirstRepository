// prog_05_02.cpp
//
// 2018.09.12


#include <iostream>

using namespace std;

void swap2(int& a, int& b) {
	int t = a;
	a = b;
	b = t;
}
/*
int main() {
	int a = 3, b = 4;

	swap2(a, b);

	cout << a << " " << b << endl;

	return 0;
}
*/