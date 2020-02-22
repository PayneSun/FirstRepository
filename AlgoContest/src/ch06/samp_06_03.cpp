// samp_06_03.cpp
//
// 2019/07/05

#include <cstdio>
#include <stack>
#include <iostream>
#include <string>


struct Matrix {
	int a, b;
	Matrix(int a = 0, int b = 0) :a(a), b(b) {}
} m[26];


std::stack<Matrix> s;


int main()
{
	int n;
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::string name;
		std::cin >> name;
		int k = name[0] - 'A';
		std::cin >> m[k].a >> m[k].b;
	}

	std::string expr;
	while (std::cin >> expr) {
		int len = expr.length();
		bool error = false;
		int ans = 0;
		for (int i = 0; i < len; ++i) {
			if (isalpha(expr[i])) {
				s.push(m[expr[i] - 'A']);
			} else if (expr[i] == ')') {
				Matrix m2 = s.top();
				s.pop();
				Matrix m1 = s.top();
				s.pop();
				if (m1.b != m2.a) {
					error = true;
					break;
				}
				ans += m1.a * m1.b * m2.b;
				s.push(Matrix(m1.a, m2.b));
			}
		}
		if (error) {
			printf("error\n");
		} else {
			printf("%d\n", ans);
		}
	}

	return 0;
}
