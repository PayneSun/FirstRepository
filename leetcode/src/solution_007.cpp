// Question 007: Reverse Integer
//
// 2019/03/08

#include <climits>


class Solution {
public:
    int reverse(int x) {
        int sign = (x >= 0) ? 1 : -1;
        x = sign * x;

        long long ret = 0;
        while (x) {
            ret = ret * 10 + x % 10;
            x /= 10;
        }
        ret = ret * sign;

        return (ret > INT_MAX || ret < INT_MIN) ? 0 : ret;
    }
};
