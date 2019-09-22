// link https://leetcode-cn.com/problems/third-maximum-number/
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int thirdMax(vector<int> &nums)
    {
        long long one, two, three;
        one = two = three = ((long long)(int)0x80000000) - 1;
        for (auto it = nums.begin(); it != nums.end(); ++it)
        {
            if (one < *it)
            {
                three = two;
                two = one;
                one = *it;
            }
            else if (one > *it && two < *it)
            {
                three = two;
                two = *it;
            }
            else if (one > *it && two > *it && three < *it)
                three = *it;
        }
        return three == ((long long)(int)0x80000000) - 1 ? one : three;
    }
};
