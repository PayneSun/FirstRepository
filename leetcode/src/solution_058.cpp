// Question 058: Length of Last Word
//
// 2019/08/05

#include <string>
#include <vector>
#include <sstream>

using namespace std;


class Solution {
public:
    int lengthOfLastWord(string s) {
        stringstream ss(s);
        string ts;
        while (ss >> ts) {
            //
        }

        return ts.size();
    }
};
