// link https://leetcode-cn.com/problems/partition-equal-subset-sum/
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int sum = 0;
        for (auto it = nums.begin(); it != nums.end(); ++it)
            sum += *it;
        if (sum % 2 == 1)
            return false;
        bool dp[10001];
        dp[0] = true;
        for (int i = 1; i <= sum / 2; ++i)
            dp[i] = false;
        for (auto it = nums.begin(); it != nums.end(); ++it)
            for (int i = sum / 2; i >= *it; --i)
                if (dp[i - *it])
                    dp[i] = true;
        return dp[sum / 2];
    }
};
