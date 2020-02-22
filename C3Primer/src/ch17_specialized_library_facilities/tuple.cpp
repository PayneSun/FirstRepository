// ch17_specialized_library_facilities
// tuple.cpp
// 2019/6/13


#include <iostream>
#include <vector>
#include <list>
#include <tuple>


int main()
{
	std::tuple<std::size_t, std::size_t> threeD;
	std::tuple<std::string, std::vector<double>, int, std::list<int>>
		someVal("constants", {3.14, 2.718}, 42, {0,1,2,3,4,5});

	auto item = std::make_tuple("0-999-78345-X", 3, 20.00);
	std::cout << std::get<0>(item) << std::endl;
	std::cout << std::get<1>(item) << std::endl;
	std::cout << std::get<2>(item) << std::endl;

	typedef decltype(item) trans;
	std::size_t sz = std::tuple_size<trans>::value;
	std::tuple_element<1, trans>::type cnt = std::get<1>(item);

	return 0;
}


