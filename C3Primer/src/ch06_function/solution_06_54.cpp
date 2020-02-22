// ch06_function
// solution_06_54.cpp
// 2019/4/10

#include <iostream>
#include <vector>


typedef int (*foo)(int, int);

int add(int v1, int v2) { return v1 + v2; }
int sub(int v1, int v2) { return v1 - v2; }
int mul(int v1, int v2) { return v1 * v2; }
int dev(int v1, int v2) { return v1 / v2; }


int main()
{
	std::vector<foo> fvec;
	fvec.push_back(&add);
	fvec.push_back(&sub);
	fvec.push_back(&mul);
	fvec.push_back(&dev);

	for (int i = 0; i < fvec.size(); ++i) {
		std::cout << (fvec[i])(5, 3) << std::endl;
	}

	return 0;
}
