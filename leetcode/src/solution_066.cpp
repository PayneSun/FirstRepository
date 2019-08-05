// Question 066: Plus One
//
// 2019/08/05

#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ivec(digits);
        reverse(ivec.begin(), ivec.end());

        int of = 0, tmp;
        for (size_t i = 0; i < ivec.size(); ++i) {
            if (i) {
                tmp = ivec[i];
                ivec[i] = (ivec[i] + of) % 10;
                of = (tmp + of) / 10;
            } else {
                of = (ivec[i] + 1) / 10;
                ivec[i] = (ivec[i] + 1) % 10;
            }
        }

        if (of) { ivec.push_back(of); }
        reverse(ivec.begin(), ivec.end());

        return ivec;
    }
};
