// ch06_function
// return_array_pointer.cpp
// 2019/4/9


#include <iostream>
#include <string>


typedef int arrT[10];
using arrT = int[10];

arrT* func1(int i);
auto func2(int i) -> int(*)[10];

