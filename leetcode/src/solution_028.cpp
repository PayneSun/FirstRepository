// Question 028: Implement strStr()
//
// 2019/03/25

#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;


class Solution {
public:
    int strStr(string haystack, string needle) {
        size_t found = haystack.find(needle);

        if (found != string::npos) {
            return found;
        } else {
            return -1;
        }
    }
};
