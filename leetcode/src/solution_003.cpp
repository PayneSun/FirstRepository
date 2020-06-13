// Question 003: Longest Substring Without Repeating Characters
//
// 2019/03/31

#include <string>

using namespace std;


class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int ret = 0, tmp;

	    std::string str;
	    for (std::size_t i = 0; i < s.size(); ++i) {
            tmp = 1;
	        for (std::size_t j = i + 1; j < s.size(); ++j) {
	            str = s.substr(i, j - i);
	            if (str.find(s[j]) == std::string::npos) {
	             	++tmp;
	            } else {
	              	if (tmp > ret) {
	               		ret = tmp;
	               	}

                    break;
	            }
	        }
            if (tmp > ret) {
	            ret = tmp;
	       	}
	    }

        return ret;
    }
};
