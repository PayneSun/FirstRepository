// Question 011: Container With Most Water
//
// 2019/07/12

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    int maxArea(vector<int>& height) {
        int ret = 0,
            left = 0, right = height.size() - 1;

        while (left < right) {
            ret = std::max(ret, std::min(height[left], height[right])*(right-left));
            if (height[left] <= height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return ret;
    }
};


int main()
{
	//
	return 0;
}
