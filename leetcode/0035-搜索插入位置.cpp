// link https://leetcode-cn.com/problems/search-insert-position/
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int index = 0;
        while (index < nums.size() && nums[index] < target)
            ++index;
        return index;
    }
};
