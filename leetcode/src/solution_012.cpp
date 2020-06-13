// Question 012: Integer to Roman
//
// 2019/07/12

#include <iostream>
#include <string>
#include <map>

using namespace std;


class Solution {
public:
    string intToRoman(int num) {
        std::map<int, std::string> svm;
        svm[1] = "I"; svm[4] = "IV"; svm[5] = "V"; svm[9] = "IX";
        svm[10] = "X"; svm[40] = "XL"; svm[50] = "L"; svm[90] = "XC";
        svm[100] = "C"; svm[400] = "CD"; svm[500] = "D"; svm[900] = "CM"; svm[1000] = "M";

        std::string retstr;
        while (num) {
            for (auto it = svm.rbegin(); it != svm.rend(); ++it) {
                if (num / it->first) {
                    retstr += it->second;
                    num -= it->first;
                    break;
                } else {
                    continue;
                }
            }
        }

        return retstr;
    }
};


int main()
{
	Solution s;
	std::cout << s.intToRoman(123) << std::endl;

	return 0;
}
