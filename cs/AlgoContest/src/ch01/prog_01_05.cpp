/*
 * prog_01_05.cpp
 * 2018/2/2
 */

#include <cstdio>
#include <cmath>

int main() {
	const double pi = acos(-1.0);
	double r, h, s1, s2, s;

	scanf("%lf%lf", &r, &h);
	s1 = pi * r * r;
	s2 = 2 * pi * r * h;
	s = 2 * s1 + s2;
	printf("Area = %.3f\n", s);

	return 0;
}
