// link https://leetcode-cn.com/problems/array-partition-i/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int arrayPairSum(vector<int> &nums)
    {
        int ret = 0;
        sort(nums.begin(), nums.end());
        for (auto it = nums.begin(); it != nums.end(); it += 2)
            ret += *it;
        return ret;
    }
};
