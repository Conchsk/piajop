// link https://leetcode-cn.com/problems/reshape-the-matrix/
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> matrixReshape(vector<vector<int>> &nums, int r, int c)
    {
        int originRow = nums.size();
        int originCol = nums[0].size();
        if (originRow * originCol != r * c)
            return nums;
        else
        {
            vector<vector<int>> ret;
            for (int i = 0; i < r; ++i)
            {
                vector<int> temp;
                for (int j = 0; j < c; ++j)
                    temp.push_back(nums[(i * c + j) / originCol][(i * c + j) % originCol]);
                ret.push_back(temp);
            }
            return ret;
        }
    }
};
