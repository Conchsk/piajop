// link https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        vector<int> ret;
        for (int i = 0; i < numbers.size(); ++i)
        {
            if (binary_search(numbers.begin() + i + 1, numbers.end(), target - numbers[i]))
            {
                ret.push_back(i + 1);
                ret.push_back(find(numbers.begin() + i + 1, numbers.end(), target - numbers[i]) - numbers.begin() + 1);
            }
            if (numbers[i] * 2 > target)
                break;
        }
        return ret;
    }
};
