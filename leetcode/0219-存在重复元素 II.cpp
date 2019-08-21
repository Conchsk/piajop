// link https://leetcode-cn.com/problems/contains-duplicate-ii/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    struct NumWithIndex
    {
        int num;
        int index;
        NumWithIndex(int num, int index) : num(num), index(index) {}
    };

    static bool cmp(NumWithIndex &a, NumWithIndex &b)
    {
        if (a.num == b.num)
            return a.index < b.index;
        return a.num < b.num;
    }

    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        vector<NumWithIndex> v;
        for (int i = 0; i < nums.size(); ++i)
            v.push_back(NumWithIndex(nums[i], i));
        sort(v.begin(), v.end(), Solution::cmp);
        for (int i = 0; i < (int)v.size() - 1; ++i)
            if (v[i].num == v[i + 1].num && v[i + 1].index - v[i].index <= k)
                return true;
        return false;
    }
};
