// link https://leetcode-cn.com/problems/transpose-matrix/
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> transpose(vector<vector<int>> &A)
    {
        vector<vector<int>> ret;
        int row = A.size();
        int col = A[0].size();
        for (int i = 0; i < col; ++i)
        {
            vector<int> v;
            for (int j = 0; j < row; ++j)
                v.push_back(A[j][i]);
            ret.push_back(v);
        }
        return ret;
    }
};
