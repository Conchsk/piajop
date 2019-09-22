// link https://leetcode-cn.com/problems/k-concatenation-maximum-sum/
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int kConcatenationMaxSum(vector<int> &arr, int k)
    {
        long long maxSum = 0;
        long long tmpSum = 0;
        for (auto it = arr.begin(); it != arr.end(); ++it)
        {
            tmpSum += *it;
            if (tmpSum < 0)
                tmpSum = 0;
            else if (maxSum < tmpSum)
                maxSum = tmpSum;
        }
        if (k == 1)
            return maxSum % 1000000007;

        long long arrSum = 0;
        long long maxPrefixSum = 0;
        long long maxSuffixSum = 0;
        for (auto it = arr.begin(); it != arr.end(); ++it)
        {
            arrSum += *it;
            if (maxPrefixSum < arrSum)
                maxPrefixSum = arrSum;
        }
        tmpSum = 0;
        for (auto it = arr.rbegin(); it != arr.rend(); ++it)
        {
            tmpSum += *it;
            if (maxSuffixSum < tmpSum)
                maxSuffixSum = tmpSum;
        }
        maxSum = max(maxSum, maxSuffixSum + (k - 2) * (arrSum > 0 ? arrSum : 0) + maxPrefixSum);
        return maxSum % 1000000007;
    }
};
