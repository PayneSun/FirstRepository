// ch17_specialized_library_facilities
// solution_17_01.cpp
// 2019/6/13


#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <utility>


int main()
{
	std::tuple<int, int, int> tt{10, 20, 30};

	std::tuple<std::string, std::vector<std::string>, std::pair<std::string, int>>
		svp_tuple{"hello", {"World"}, std::make_pair("You", 30)};

	std::cout << std::get<0>(tt) << std::endl;
	std::cout << std::get<1>(svp_tuple)[0] << std::endl;
	std::cout << std::get<2>(svp_tuple).first << std::endl;

	typedef decltype(tt) trans;
	std::size_t sz = std::tuple_size<trans>::value;
	std::tuple_element<1, trans>::type cnt = std::get<1>(tt);
	std::cout << sz << std::endl;
	std::cout << cnt << std::endl;

	return 0;
}


