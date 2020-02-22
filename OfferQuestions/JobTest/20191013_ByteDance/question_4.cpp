// 字节跳动-后端开发
//
// 2019/10/14

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


bool isValid(const string &cstr) {
	vector<char> svec;
	for (int i = 0; i < cstr.size(); ++i) {
		svec.push_back(cstr[i]);
	}

	sort(svec.begin(), svec.end());
	bool ret = true;
	for (int i = 0; i < svec.size(); ++i) {
		if (i && svec[i] == svec[i-1]) {
			return false;
		}
	}

	return ret;
}


int main()
{
	string instr;
	cin >> instr;

	int len = 0;
	for (int i = 0; i < instr.size(); ++i) {
		for (int j = i + 1; j < instr.size(); ++j) {
			if (isValid(instr.substr(i, j-i))) {
				if (instr.substr(i, j-i).size() > len) {
					len = instr.substr(i, j-i).size();
				}
			}
		}
	}
	cout << len << endl;

	return 0;
}

/*
87 33 29 99 10 55 88 63 71 43

['铜', '8', '9', '金', '10', '6', '银', '5', '4', '7']

 */
