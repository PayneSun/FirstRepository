// ch3_data
// inherit_data_member.cpp
// 2019/5/16


#include <iostream>


class Point2d {
public:
	Point2d(float x = 0.0, float y = 0.0)
		: _x(x), _y(y) {};
	float x() { return _x; }
	float y() { return _y; }
	void x(float x) { _x = x; }
	void y(float y) { _y = y; }
	virtual float z() { return 0.0; }
	virtual void z(float) {}
	void operator+=(const Point2d &rhs) {
		_x += rhs.x();
		_y += rhs.y();
	}
protected:
	float _x, _y;
};


class Point3d: public Point2d {
public:
	Point3d(float x = 0, float y = 0, float z = 0)
		: Point2d(x, y), _z(z) {}
	float z() { return _z; }
	void operator+=(const Point2d &rhs) {  //notice: Point2d
		Point2d::operator +=(rhs);
		_z += rhs.z();
	}
protected:
	float _z;
};


int main()
{
	Point3d p3d;

	p3d.foo(5.6);

	std::cout << p3d.foo() << std::endl;

	return 0;
}
