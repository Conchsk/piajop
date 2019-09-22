// link https://leetcode-cn.com/problems/spiral-matrix/
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> ret;

        int rowStart = -1;
        int rowEnd = matrix.size();
        if (rowEnd == 0)
            return ret;
        int colStart = -1;
        int colEnd = matrix[0].size();

        int direction = 0;
        int rowAdd[]{0, 1, 0, -1};
        int colAdd[]{1, 0, -1, 0};

        int rowTemp = 0;
        int colTemp = 0;
        while (rowStart < rowEnd - 1 && colStart < colEnd - 1)
        {
            ret.push_back(matrix[rowTemp][colTemp]);
            rowTemp += rowAdd[direction];
            colTemp += colAdd[direction];
            if (colTemp == colEnd)
            {
                ++rowStart;
                ++rowTemp, --colTemp;
                direction = (direction + 1) % 4;
            }
            else if (rowTemp == rowEnd)
            {
                --colEnd;
                --rowTemp, --colTemp;
                direction = (direction + 1) % 4;
            }
            else if (colTemp == colStart)
            {
                --rowEnd;
                --rowTemp, ++colTemp;
                direction = (direction + 1) % 4;
            }
            else if (rowTemp == rowStart)
            {
                ++colStart;
                ++rowTemp, ++colTemp;
                direction = (direction + 1) % 4;
            }
        }
        return ret;
    }
};
