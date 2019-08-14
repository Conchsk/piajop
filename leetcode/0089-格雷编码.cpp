// link https://leetcode-cn.com/problems/gray-code/
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> grayCode(int n)
    {
        vector<int> ret;
        int size = 1 << n;
        for (int i = 0; i < size; ++i)
            ret.push_back(i ^ (i >> 1));
        return ret;
    }
};