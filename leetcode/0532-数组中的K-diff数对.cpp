// link https://leetcode-cn.com/problems/k-diff-pairs-in-an-array/
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int findPairs(vector<int> &nums, int k)
    {
        int ret = 0;
        if (k >= 0)
        {
            unordered_multiset<int> mySet;
            for (auto it = nums.begin(); it != nums.end(); ++it)
            {
                int count = mySet.count(*it);
                switch (count)
                {
                case 0:
                    if (k != 0)
                    {
                        if (mySet.count(*it - k))
                            ++ret;
                        if (mySet.count(*it + k))
                            ++ret;
                    }
                    mySet.insert(*it);
                    break;
                case 1:
                    if (k == 0)
                    {
                        ++ret;
                        mySet.insert(*it);
                    }
                    break;
                default:
                    break;
                }
            }
        }
        return ret;
    }
};
