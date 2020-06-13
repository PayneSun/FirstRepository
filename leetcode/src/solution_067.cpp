// Question 067: Add Binary
//
// 2019/08/05

#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;


class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        string ret;
        int of = 0, i = 0, j = 0;
        while (i < a.size() && j < b.size()) {
            if (a[i] - '0' + b[j] - '0' + of > 1) {
                ret += '0' + (a[i] - '0' + b[j] - '0' + of) % 2;
                of = (a[i] - '0' + b[j] - '0' + of) / 2;
            } else {
                ret += '0' + (a[i] - '0' + b[j] - '0' + of);
                of = 0;
            }
            ++i, ++j;
        }

        while (i < a.size()) {
            if (a[i] - '0' + of > 1) {
                ret += '0' + (a[i] - '0' + of) % 2;
                of = (a[i] - '0' + of) / 2;
            } else {
                ret += '0' + (a[i] - '0' + of);
                of = 0;
            }
            ++i;
        }

        while (j < b.size()) {
            if (b[j] - '0' + of > 1) {
                ret += '0' + (b[j] - '0' + of) % 2;
                of = (b[j] - '0' + of) / 2;
            } else {
                ret += '0' + (b[j] - '0' + of);
                of = 0;
            }
            ++j;
        }

        if (of) { ret += '0' + of; }

        reverse(ret.begin(), ret.end());

        return ret;
    }
};
