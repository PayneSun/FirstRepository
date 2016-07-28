//------Chapter11_1.1
#include <map>
#include <cstddef>

map<string, size_t> word_count;
string word;
while (cin >> word)
	++word_count[word];
for (const auto &w : word_count)
	cout << w.first << " occurs " << w.second
		<< ((w.second > 1) ? " times" : " time") << endl;
//------
		
//------Chapter11_1.2
#include <map>
#include <set>
#include <cstddef>

map<string, size_t> word_count;
set<string> exclude = { "The", "But", "And", "Or", "An", "A", "the", "but", "and", "or", "an", "a"}; 
string word;
while (cin >> word)
	if (exclude.find(word) == exclude.end())
		++word_count[word];
//------

//------Chapter11_2.1
vector<int> ivec;
for (vector<int>::size_type i = 0; i != 10; i++) {
	ivec.push_back(i);
	ivec.push_back(i);
}

set<int> iset(ivec.cbegin(), ivec.cend());
multiset<int> miset(ivec.cbegin(), ivec.cend());
cout << ivec.size() << endl;
cout << iset.size() << endl;
cout << miset.size() << endl;
//------

//------Chapter11_2.2
pair<string, int>
process(vector<string> &v)
{
	if (!v.empty())
		return {v.back(), v.back().size()};
	else
		return pair<string, int>();
}
//------

//------Chapter11_3.1
set<string>::value_type v1;        //string
set<string>::key_type v2;	       //string
map<string, int>::value_type v3;   //pair<const string, int>
map<string, int>::key_type v4;	   //string
map<string, int>::mapped_type v5;  //int
//------

//------Chapter11_3.2
auto map_it = word_count.begin();
cout << map_it->first;
cout << " " << map_int->second;
map_it->first = "new key"; // error, const
++map_it->second;
//------

//------Chapter11_3.3
set<int> iset = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
set<int>::iterator set_it = iset.begin();
if (set_it != iset.end()) {
	*set_it = 42;  //error
	cout << *set_it << endl;
	++iset;
}
//------

//------Chapter11_3.4
map<string, size_t> word_count;
string word;
while (cin >> word) {
	auto ret = word_count.insert({word, 1});
	if (!ret.second)
		++ret.first->second;
}
//------

//------Chapter11_3.5
string search_item("Alain de Botton");
auto entries = authors.count(search_item);
auto iter = authors.find(search_item);
while (entries) {
	cout << itre->second << endl;
	++iter;
	--entries;
}
//------

//------Chapter11_3.6
for (auto beg = authors.lower_bound(search_item),
		  end = authors.upper_bound(search_item);
	 beg != end; ++beg)
	 cout << beg->second << endl;
//------

//------Chapter11_3.7
for (auto pos = authors.equal_range(search_item); 
	 pos.first != pos.second; ++pos.first)
	 cout << pos.first->second << endl;
//------

//------Chapter11_3.8
void word_transform(ifstream &map_file, ifstream &input)
{
	auto trans_map = buildMap(map_file);
	string text;
	while (getline(input, text)) {
		istringstream stream(text);
		string word;
		bool firstword = true;
		while (stream >> word) {
			if (firstword)
				firstword = false;
			else
				cout << " ";
			cout << transform(word, trans_map);
		}
		cout << endl;
	}
}

map<string, string> buildMap(ifstream &map_file)
{
	map<string, string> trans_map;
	string key;
	string value;
	while (map_file >> key && getline(map_file, value))
		if (value.size() > 1)
			trans_map[key] = value.substr(1);
		else
			throw runtime_error("no rule for " + key);
	return trans_map;
}

const string &
transform(const string &s, const map<string, string> &m)
{
	auto map_it = m.find(s);
	
	if (map_it != m.cend())
		return map_it->second;
	else
		return s;
}
//------

//------Chapter11_4.1
#include <unordered_map>
unordered_map<string, size_t> word_count;
string word;
while (cin >> word)
	++word_count[word];
for (const auto &w : word_count)
	cout << w.first << " occurs " << w.second
		 << ((w.second > 1) ? " times" : " time") << endl;
//------
