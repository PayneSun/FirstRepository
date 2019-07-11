// prog_05_04.cpp
//
// 2018.09.12

#include <iostream>

using namespace std;

//
template<typename T>
struct Point {
	T x, y;
	Point(T x = 0, T y = 0) : x(x), y(y) {}
};

//
template<typename T>
Point<T> operator+(const Point<T>& A, const Point<T>& B) {
	return Point<T>(A.x + B.x, A.y + B.y);
}

//
template<typename T>
ostream& operator<<(ostream& out, const Point<T>& p) {
	out << "(" << p.x << "," << p.y << ")";
	return out;
}

//
template<typename T>
T sum(T* begin, T* end) {
	T ans = 0;
	for (T* p = begin; p != end; ++p) {
		ans = ans + *p;
	}
	return ans;
}
/*
int main() {
	Point<int> a, b(1, 2);
	a.x = 3;

	cout << a + b << endl;

	return 0;
}
*/