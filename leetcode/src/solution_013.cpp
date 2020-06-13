// Question 013: Roman to Integer
//
// 2019/03/08

#include <map>
#include <iostream>


class Solution {
public:
    int romanToInt(std::string s) {
        std::map<char,int> mci;
        mci['I'] = 1;
        mci['V'] = 5;
        mci['X'] = 10;
        mci['L'] = 50;
        mci['C'] = 100;
        mci['D'] = 500;
        mci['M'] = 1000;

        int ret = 0;
        for (std::size_t i = 0; i < s.size(); i++) {
            if (i != s.size() - 1) {
                if (mci[s[i]] < mci[s[i+1]]) {
                    ret -= mci[s[i]];
                } else {
                    ret += mci[s[i]];
                }
            } else {
                ret += mci[s[i]];
            }
        }

        return ret;
    }
};
