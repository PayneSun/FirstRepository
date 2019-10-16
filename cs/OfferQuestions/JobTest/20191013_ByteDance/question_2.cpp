// 字节跳动-后端开发
//
// 2019/10/14

#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;


bool isValid(string &cstr) {
	stack<int> stk;

	for (int i = 0; i < cstr.size(); ++i) {
		if (cstr[i] == '(') {
			stk.push(0);
		} else if (cstr[i] == ')') {
			if (!stk.empty()) {
				stk.pop();
			} else {
				return false;
			}
		}
	}

	return stk.empty();
}


int main()
{
	string instr;
	cin >> instr;

	int nl = 0, nr = 0;
	for (auto r : instr) {
		if (r == '(') {
			nl++;
		} else if (r == ')') {
			nr++;
		}
	}

	int delta = (nl > nr) ? (nl - nr) : (nr - nl);

	string tstr;
	vector<string> svec;
	for (int i = 0; i < instr.size(); ++i) {
		if (instr[i] == '(' || instr[i] == ')') {
			tstr = instr.substr(0,i) + instr.substr(i+1, instr.size()-i-1);
			if (isValid(tstr)) {
				svec.push_back(tstr);
			}
		}
	}

	sort(svec.begin(), svec.end());
	cout << "[";
	for (int i = 0; i < svec.size(); ++i) {
		if (i == 0) {
			cout << "\"" << svec[i] << "\"";
		} else {
			if (svec[i] != svec[i-1]) {
				cout << ", \"" << svec[i] << "\"";
			}
		}
	}
	cout << "\"]" << endl;
	return 0;
}

/*
()())()

["()()()", "(())()"]


(a)())()
["(a)()()", "(a())()"]

 */
