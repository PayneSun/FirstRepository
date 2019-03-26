/*
 * LeetCode
 * Question 038: Count and Say
 * 2019/3/26
 */

#include <string>
#include <sstream>

using namespace std;


class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) {
        	return "1";
        }

        stringstream ret;
        string str = countAndSay(n-1);
        char chr = str[0];
        int cnt = 1;
        for (size_t i = 1; i < str.size(); ++i) {
            if (str[i] == chr) {
                cnt++;
            } else {
                ret << cnt << chr;
                chr = str[i];
                cnt = 1;
            }
        }
        ret << cnt << chr;
        return ret.str();
    }
};
