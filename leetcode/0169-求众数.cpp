// link https://leetcode-cn.com/problems/majority-element/
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        // only work when the majority's occurrences greater than n/2
        int ret, count = 0;
        for (auto it = nums.begin(); it != nums.end(); ++it)
        {
            if (count == 0)
            {
                ret = *it;
                ++count;
            }
            else
            {
                if (ret != *it)
                    --count;
                else
                    ++count;
            }
        }
        return ret;
    }
};
