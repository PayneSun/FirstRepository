/*
 * LeetCode
 * Question 020: Valid Parentheses
 * 2019/3/22
 */

#include <string>
#include <stack>

using namespace std;


class Solution {
public:
    bool isValid(string s) {
    	stack<char> sc;

    	for (size_t i = 0; i < s.length(); ++i) {
    		if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
    			sc.push(s[i]);
    		} else {
                if (sc.empty()) {
                    return false;
                }
    			if (sc.top() == '(' && s[i] == ')') {
    				sc.pop();
    			} else if (sc.top() == '[' && s[i] == ']') {
    				sc.pop();
    			} else if (sc.top() == '{' && s[i] == '}') {
    				sc.pop();
    			} else {
    				break;
    			}
    		}
    	}

    	if (sc.empty()) {
    		return true;
    	} else {
    		return false;
    	}
    }
};
