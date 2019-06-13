#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    class Helper
    {
    public:
        int fixed, fixedAdd, floatStart, floatEnd, floatAdd, floatOrder, floatTemp;

        Helper(int fixed, int fixedAdd, int floatStart, int floatEnd, int floatAdd, int floatOrder)
        {
            this->fixed = fixed;
            this->fixedAdd = fixedAdd;
            this->floatStart = floatStart;
            this->floatEnd = floatEnd;
            this->floatAdd = floatAdd;
            this->floatOrder = floatOrder;
            floatTemp = floatStart;
        }

        void getNextPos(int &i, int &j)
        {
            if (floatAdd * floatTemp < floatAdd * floatEnd)
            {
                if (floatOrder == 0)
                {
                    i = floatTemp;
                    j = fixed;
                }
                else
                {
                    i = fixed;
                    j = floatTemp;
                }
                floatTemp += floatAdd;
            }
            else
            {
                fixed += fixedAdd;
                floatStart += floatAdd;
                floatEnd -= floatAdd;
                floatTemp = floatStart;
                i = -1;
                j = -1;
            }
        }
    };

    vector<int> printMatrix(vector<vector<int>> matrix)
    {
        vector<int> ret;
        int height = matrix.size();
        int width = matrix[0].size();

        Helper helper[] = {Helper(0, 1, 0, width, 1, 1),
                           Helper(width - 1, -1, 1, height, 1, 0),
                           Helper(height - 1, -1, width - 2, -1, -1, 1),
                           Helper(0, 1, height - 2, 0, -1, 0)};
        int direction = 0;
        int flag = 0;

        while (flag < 2)
        {
            int i, j;
            helper[direction].getNextPos(i, j);
            if (i == -1 && j == -1)
            {
                direction = (direction + 1) % 4;
                flag++;
            }
            else
            {
                ret.push_back(matrix[i][j]);
                flag = 0;
            }
        }
        return ret;
    }
};
