// Question 069: Sqrt(x)
//
// 2019/08/05

#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;


class Solution {
public:
    int mySqrt(int x) {
        long long i = 0;
        while (i * i <= x) {
            ++i;
        }

        return i-1;
    }
};
