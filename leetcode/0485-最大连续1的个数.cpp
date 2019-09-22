// link https://leetcode-cn.com/problems/max-consecutive-ones/
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int maxCount = 0;
        int tmpCount = 0;
        for (auto it = nums.begin(); it != nums.end(); ++it)
        {
            if (*it == 0)
                tmpCount = 0;
            else
                ++tmpCount;
            if (maxCount < tmpCount)
                maxCount = tmpCount;
        }
        return maxCount;
    }
};
