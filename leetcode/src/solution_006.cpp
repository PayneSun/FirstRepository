// Question 006: ZigZag Conversion
//
// 2019/08/05

#include <string>

using namespace std;


class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }

        vector<string> rows(min(numRows,int(s.size())));
        int curRow = 0;
        bool gr = false;

        for (auto c : s) {
            rows[curRow] += c;
            if (curRow == 0 || curRow == numRows - 1) {
                gr = !gr;
            }
            curRow += gr ? 1 : -1;
        }

        string ret;
        for (auto row : rows) {
            ret += row;
        }

        return ret;
    }
};
