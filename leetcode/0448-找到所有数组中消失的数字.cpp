// link https://leetcode-cn.com/problems/find-all-numbers-disappeared-in-an-array/
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
        vector<int> ret;
        for (auto it = nums.begin(); it != nums.end(); ++it)
            nums[(*it - 1) % nums.size()] += nums.size();
        for (int i = 0; i < nums.size(); ++i)
            if (nums[i] <= nums.size())
                ret.push_back(i + 1);
        return ret;
    }
};
