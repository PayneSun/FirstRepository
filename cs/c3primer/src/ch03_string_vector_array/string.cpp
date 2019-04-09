// ch03_string_vector_array
// string.cpp
// 2019/3/26


#include <iostream>
#include <string>
#include <cctype>

using std::string;


string s1;
string s2 = s1;
string s3 = "hiya";
string s4(10, 'c');

int main()
{
//	string s;
//	std::cin >> s;
//	std::cout << s << std::endl;

//	string line;
//	while (getline(std::cin, line)) {
//		if (!line.empty()) {
//			std::cout << line << std::endl;
//		}
//	}

	string s("Hello World!!!");
	decltype(s.size()) punct_cnt = 0;
	for (auto c : s) {
		if (ispunct(c)) {
			++punct_cnt;
		}
	}
	std::cout << punct_cnt << " punctuation characters in " << s << std::endl;

}
