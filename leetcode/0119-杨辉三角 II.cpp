// link https://leetcode-cn.com/problems/pascals-triangle-ii/
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> ret;
        for (int i = 0; i < rowIndex + 1; ++i)
        {
            for (int j = 0; j < i; ++j)
                ret[j] += ret[j + 1];
            ret.insert(ret.begin(), 1);
        }
        return ret;
    }
};
